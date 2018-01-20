#include "histogram.h"

histogram_t * histogram_image(const image_t * image) {
    assert(image);
    histogram_t * that = malloc(sizeof(histogram_t));
    if(image->height == 0 || image->width == 0)
        return NULL;

    that->intensity = malloc(sizeof(int) * 256);
    if(!that->intensity)
        out_of_memory("histogram_image");

    for(size_t i = 0; i < 256; i++)
        that->intensity[i] = 0;

    for(size_t line = 0; line < image->height; line++)
        for(size_t column = 0; column < image->width; column++)
            that->intensity[get_pixel_image(image, line, column)]++;
    return that;
}

void delete_histogram(histogram_t * histogram) {
    free(histogram->intensity);
    free(histogram);
}

int write_histogram(const histogram_t * histogram, const char * filepath) {
    int total_intensity = 0;
    for(size_t i = 0; i < 256; i++)
        total_intensity += histogram->intensity[i];
    image_t * histogram_image = create_image_hw(256, 256);
    for(size_t column = 0; column < 256; column++) {
        uint8_t intensity = 255 - (uint8_t)(histogram->intensity[column] * 255 * 100 / total_intensity);
        for(size_t line = 0; line < intensity; line++)
            set_pixel_image(histogram_image, line, column, 255);
        for(size_t line = intensity; line < 256; line++)
            set_pixel_image(histogram_image, line, column, 0);
    }
    int retrn = write_image(histogram_image, filepath, "Histogramme");
    delete_image(histogram_image);
    return retrn;
}
