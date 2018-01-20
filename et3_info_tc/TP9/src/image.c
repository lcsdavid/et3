#include "image.h"

image_t * create_image(int height, int width, int vmax) {
    image_t * that = malloc(sizeof(image_t));
    that->height = height;
    that->width = width;
    that->vmax = vmax;
    that->pixels = malloc(sizeof(uint8_t*) * height);
    if(!that->pixels)
        out_of_memory("create_image");
    for(size_t i = 0; i < height; i++) {
        that->pixels[i] = malloc(sizeof(uint8_t) * width);
        if(!that->pixels[i])
            out_of_memory("create_image");
        for(size_t j = 0; j < width; j++)
            that->pixels[i][j] = 255;
    }
    return that;
}

image_t * create_image_hw(int height, int width) {
    return create_image(height, width, 255);
}

image_t * copy_image(const image_t * image) {
    assert(image);
    image_t * that = create_image(image->height, image->width, image->vmax);
    that->height = image->height;
    that->width = image->width;
    that->vmax = image->vmax;
    for(size_t i = 0; i < that->height; i++)
        for(size_t j = 0; j < that->width; j++)
            that->pixels[i][j] = image->pixels[i][j];
    return that;
}

void delete_image(image_t * image) {
    assert(image);
    for(size_t i = 0; i < image->height; i++)
        free(image->pixels[i]);
    free(image->pixels);
    free(image);
}

uint8_t get_pixel_image(const image_t * image, size_t line, size_t column) {
    assert(image);
    if(line >= image->height || column >= image->width)
        out_of_bounds("get_pixel_image");
    return image->pixels[line][column];
}

void set_pixel_image(image_t * image, size_t line, size_t column,
    uint8_t value) {
    assert(image);
    if(line > image->height || column > image->width)
        out_of_bounds("set_pixel_image");
    if(value > image->vmax)
        image->vmax = value;
    image->pixels[line][column] = value;
}


image_t * read_image(const char * filepath) {
    FILE * file = fopen(filepath, "r");
    int c = 0;
    int h, w, v;
    if(!file) {
        printf("File may not exist or filepath given is wrong...\n");
        return NULL;
    }
    if(fgetc(file) != 'P' || fgetc(file) != '2') {
        printf("File is not PGM nor mode P2.\n");
        return NULL;
    }
    while(fgetc(file) != '\n');

    if((c = fgetc(file)) == '#')
        while(fgetc(file) != '\n');
    else
        ungetc(c, file);
    fscanf(file, "%d %d", &h, &w);
    while(fgetc(file) != '\n');

    if((c = fgetc(file)) == '#')
        while(fgetc(file) != '\n');
    else
        ungetc(c, file);
    fscanf(file, "%d", &v);
    while(fgetc(file) != '\n');

    image_t * image = create_image(h, w, v);
    uint8_t pixel = 0;
    for(size_t i = 0; i < h; i++) {
        if((c = fgetc(file)) == '#')
            while(fgetc(file) != '\n');
        else
            ungetc(c, file);
        for(size_t j = 0; j < w - 1; j++) {
            fscanf(file, "%hhu ", &pixel);
            set_pixel_image(image, i, j, pixel);
        }
        fscanf(file, "%hhu\n", &pixel);
        set_pixel_image(image, i, w - 1, pixel);
    }
    printf("Image %s loaded.\n", filepath);
    return image;
}

int write_image(const image_t * image, const char * filepath,
    const char * desc) {
    assert(image);
    FILE * file = fopen(filepath, "w");
    if(!file) {
        printf("Error happened while creating/opening file.\n");
        return 0;
    }
    fprintf(file, "P2\n");
    fprintf(file, "# %s\n", desc);
    fprintf(file, "%d %d\n%d\n", image->height, image->width, image->vmax);
    for(size_t i = 0; i < image->height; i++) {
        for(size_t j = 0; j < image->width - 1; j++)
            fprintf(file, "%hhu ", get_pixel_image(image, i, j));
        fprintf(file, "%hhu\n", get_pixel_image(image, i, image->width - 1));
    }
    printf("Image %s created.\n", filepath);
    return 1;
}

image_t * adapt_contrast_image(image_t * image, float k) {
    assert(image);
    uint8_t pixel = 0;
    for(size_t i = 0; i < image->height; i++)
        for(size_t j = 0; j < image->width; j++) {
            pixel = min(max(k * get_pixel_image(image, i, j), image->vmax), 0);
            set_pixel_image(image, i, j, pixel);
    }
    return image;
}

image_t * grey_to_bw(image_t * image) {
    assert(image);
    histogram_t * histogram = histogram_image(image);
    int max = 0; uint8_t s = 0;
    for(size_t i = 0; i < 256; i++) {
        if(histogram->intensity[i] > max) {
            max = histogram->intensity[i];
            s = i;
        } else if(histogram->intensity[i] == max)
            if(abs(s - 128) > abs(i - 128))
                s = i;
    }

    for(size_t line = 0; line < image->height; line++)
        for(size_t column = 0; column < image->width; column++) {
            if(get_pixel_image(image, line, column) < s)
                set_pixel_image(image, line, column, 0);
            else
                set_pixel_image(image, line, column, 1);
        }
    image->vmax = 1;
	return image;
}

image_t * erosion(image_t * image) {
    assert(image);
    uint8_t ** erosion = malloc(sizeof(uint8_t*) * image->height);
    if(!erosion)
        out_of_memory("erosion");
    for(size_t line = 0; line < image->height; line++) {
        erosion[line] = malloc(sizeof(uint8_t) * image->width);
        if(!erosion[line])
            out_of_memory("erosion");
    }

    for(size_t line = 1; line < image->height - 1; line++)
        for(size_t column = 1; column < image->width - 1; column++)
            erosion[line][column] = min(min(min(min(min(min(min(min(
                get_pixel_image(image, line - 1, column -1),
                get_pixel_image(image, line - 1, column)),
                get_pixel_image(image, line - 1, column + 1)),
                get_pixel_image(image, line, column - 1)),
                get_pixel_image(image, line, column)),
                get_pixel_image(image, line, column + 1)),
                get_pixel_image(image, line + 1, column - 1)),
                get_pixel_image(image, line + 1, column)),
                get_pixel_image(image, line + 1, column + 1));

    for(size_t line = 0; line < image->height; line++)
        free(image->pixels[line]);
    free(image->pixels);
    image->pixels = erosion;
	return image;
}

image_t * dilation(image_t * image) {
    assert(image);
    uint8_t ** dilation = malloc(sizeof(uint8_t*) * image->height);
    if(!dilation)
        out_of_memory("dilation");
    for(size_t line = 0; line < image->height; line++) {
        dilation[line] = malloc(sizeof(uint8_t) * image->width);
        if(!dilation[line])
            out_of_memory("dilation");
    }

    for(size_t line = 1; line < image->height - 1; line++)
        for(size_t column = 1; column < image->width - 1; column++)
            dilation[line][column] = max(max(max(max(max(max(max(max(
                get_pixel_image(image, line - 1, column - 1),
                get_pixel_image(image, line - 1, column)),
                get_pixel_image(image, line - 1, column + 1)),
                get_pixel_image(image, line, column - 1)),
                get_pixel_image(image, line, column)),
                get_pixel_image(image, line, column + 1)),
                get_pixel_image(image, line + 1, column - 1)),
                get_pixel_image(image, line + 1, column)),
                get_pixel_image(image, line + 1, column + 1));

    for(size_t line = 0; line < image->height; line++)
        free(image->pixels[line]);
    free(image->pixels);
    image->pixels = dilation;
	return image;
}

image_t * opening(image_t * image) {
	assert(image);
	return dilation(erosion(image));
}

image_t * closing(image_t * image) {
	assert(image);
	return erosion(dilation(image));
}