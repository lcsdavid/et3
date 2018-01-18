#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include "image.h"
#include "utility.h"

typedef struct {
    size_t values_number;
    uint8_t ** gamut;
} histogram_t;

/* Basic constructor */
histogram_t * histogram_image(const image_t * image);

/* Draw histogram in file (filepath). Return 1 if succeed, 0 else. */
int write_histogram(const histogram_t * histogram, const char * filepath);

#endif
