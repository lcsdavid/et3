#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include "image.h"
#include "utility.h"

typedef struct Image image_t;

/**
 * /struct histogram_t as the number of pixel for each intensity (proportion[256]) of grey (between 0 and 255) of a given image_t.
 */
typedef struct Histogram {
    int * proportion;
} histogram_t;

/**
 * Constructor of histogram_t type.
 * Count number of pixel for each intensity of grey (between 0 and 255).
 * @param image Evaluated image_t.
 * @return If image not valid : NULL else histogram_t of image.
 */
histogram_t * histogram_image(const image_t * image);

/**
 * Delete allocated memory.
 * @param histogram to delete.
 */
void delete_histogram(histogram_t * histogram);

/**
 * Draw histogram in an image_t and save it.
 * @param histogram histogram_t to draw and save.
 * @param filepath location of file.
 * @return If success : 1 else 0.
 */
int write_histogram(const histogram_t * histogram, const char * filepath);

#endif
