#include "image.h"

image_t * create_image(int height, int width, int vmax) {
    image_t * that = malloc(sizeof(image_t));
	if(!that)
		out_of_memory("image.c: line 4, create_image");
    that->height = height;
    that->width = width;
    that->vmax = vmax;
    that->pixels = malloc(sizeof(uint8_t*) * height);
    if(!that->pixels)
        out_of_memory("image.c: line 10, create_image");
    for(size_t i = 0; i < height; i++) {
        that->pixels[i] = malloc(sizeof(uint8_t) * width);
        if(!that->pixels[i])
            out_of_memory("image.c: line 14, create_image");
        for(size_t j = 0; j < width; j++)
            that->pixels[i][j] = vmax;
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
        out_of_bounds("image.c: line 49, get_pixel_image");
    return image->pixels[line][column];
}

void set_pixel_image(image_t * image, size_t line, size_t column, uint8_t value) {
    assert(image);
    if(line > image->height || column > image->width)
        out_of_bounds("image.c: line 56, set_pixel_image");
    if(value > image->vmax)
        image->vmax = value;
    image->pixels[line][column] = value;
}


image_t * read_image(const char * filepath) {
    FILE * file = fopen(filepath, "r");
	if(!file) {
        printf("File may not exist or filepath given is wrong...\n");
        return NULL;
    }
	int h, w, v;
	char buffer[16];
	skip_comments(file);
	if(fscanf(file, "%s", buffer) != 1) {
		printf("File corrupted!\n");
        return NULL;
	}
    if(strcmp(buffer, "P2") != 0) { /* Mode */
        printf("File corrupted or not in right mode!\n");
        return NULL;
    } 
	end_line(file);
    skip_comments(file);
    if(fscanf(file, "%d %d\n", &w, &h) != 2) { /* Height and width */
		printf("File corrupted!\n");
        return NULL;
    }
    skip_comments(file);
    if(fscanf(file, "%d\n", &v) != 1) { /* Value max */
		printf("File corrupted!\n");
        return NULL;
    }
	skip_comments(file);
    image_t * image = create_image(h, w, v);
    uint8_t pixel = 0;
    for(size_t i = 0; i < h; i++) {
        for(size_t j = 0; j < w; j++) {
			skip_comments(file);
            if(fscanf(file, "%hhu", &pixel) != 1) {
				if(ferror(file) || feof(file)) {
					printf("File corrupted!\n");
					return NULL;
				}
			}
            set_pixel_image(image, i, j, pixel);
        }
	}
	if(!check_eof(file)) {
		printf("File corrupted.\n");
		return NULL;
	}
	printf("Image %s loaded.\n", filepath);
	fclose(file);
    return image;
}

int write_image(const image_t * image, const char * filepath, const char * desc) {
    assert(image);
    FILE * file = fopen(filepath, "w");
    if(!file) {
        printf("Error happened while creating/opening file.\n");
        return 0;
    }
    fprintf(file, "P2\n"); /* Mode */
    fprintf(file, "# %s\n", desc); /* Description */
    fprintf(file, "%d %d\n", image->width, image->height); /* Width, height */
	fprintf(file, "%d\n", image->vmax); /* Vmax */
    for(size_t i = 0; i < image->height; i++) {
        for(size_t j = 0; j < image->width - 1; j++) {
            fprintf(file, "%hhu ", get_pixel_image(image, i, j));
			if(ferror(file)) {
				printf("Error writing to %s.\n", filepath);
				return 0;
			}
		}
        fprintf(file, "%hhu\n", get_pixel_image(image, i, image->width - 1));
		if(ferror(file)) {
			printf("Error writing to %s.\n", filepath);
			return 0;
		}
    }
    printf("Image %s created.\n", filepath);
	fclose(file);
    return 1;
}

image_t * adapt_contrast_image(image_t * image, float k) {
    assert(image);
    for(size_t i = 0; i < image->height; i++)
        for(size_t j = 0; j < image->width; j++)
            set_pixel_image(image, i, j, max(min(k * get_pixel_image(image, i, j), image->vmax), 0));
    return image;
}

image_t * grey_to_bw(image_t * image) {
    assert(image);
    histogram_t * histogram = histogram_image(image);
    int max = 0; 
	uint8_t s = 0;
    for(size_t i = 0; i < 256; i++) { /* Set an arbitrary s in function of grey scale */
        if(histogram->proportion[i] > max) {
            max = histogram->proportion[i];
            s = i;
        } else if(histogram->proportion[i] == max)
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