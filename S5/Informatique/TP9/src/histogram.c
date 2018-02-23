#include "histogram.h"

histogram_t * histogram_image(const image_t * image) {
    assert(image);
    histogram_t * that = malloc(sizeof(histogram_t));
	if(!that)
		out_of_memory("histogram.c: line 5, histogram_image");
	
	if(image->height < 1 || image->width < 1)
        return NULL;
	
	that->size = image->vmax + 1;
		
	that->proportion = malloc(that->size * sizeof(int));
	
    for(size_t i = 0; i < that->size; i++)
        that->proportion[i] = 0;

    for(size_t line = 0; line < image->height; line++)
        for(size_t column = 0; column < image->width; column++)
            that->proportion[get_pixel_image(image, line, column)]++;
    return that;
}

void delete_histogram(histogram_t * histogram) {
	free(histogram->proportion);
    free(histogram);
}

int write_histogram(const histogram_t * histogram, const char * filepath) {
	int histogram_height = 128;
	int max_proportion = 0;
    int number_of_pixel = 0;
	for(size_t i = 0; i < histogram->size; i++) {
		number_of_pixel += histogram->proportion[i];
		max_proportion = max(max_proportion, histogram->proportion[i]);
	}
	
	float max_percentage = 100 * max_proportion / (float)number_of_pixel; /* Percentage of pixel == 100% on graph. */
	float graduation = 99 / max_percentage; /* Graduation unit */
	
	printf("%d\n", histogram->size);
	
    image_t * histogram_image = create_image(histogram_height, histogram->size, 1);
    for(size_t column = 0; column < histogram->size; column++) {
		printf("%d\n", column);
		float percentage = histogram->proportion[column] / (float)number_of_pixel; /* True percentage */
		printf("%d\n", column);
		float histo_value = percentage * histogram_height * graduation; /* Visual percentage */
		for(size_t line = histogram_height; histogram_height - (int)histo_value < line || line < 0; line--)
            set_pixel_image(histogram_image, line, column, 0);
		printf("%d\n", column);
    }
    int success = write_image(histogram_image, filepath, "pgm v1.1, histogram");
    delete_image(histogram_image);
    return success;
}
