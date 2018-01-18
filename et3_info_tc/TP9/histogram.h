#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include "image.h"
#include "utility.h"

typedef struct {
    size_t size;
    uint8_t * intensity;
} histogram_t;

/* Basic constructor */
histogram_t * histogram_image(const image_t * image);

/* Free histogram */
void delete_histogram(histogram_t * histogram);

/* Draw histogram in file (filepath). Return 1 if succeed, 0 else. */
int write_histogram(const histogram_t * histogram, const char * filepath);

#endif
