#ifndef IMAGE_H
#define IMAGE_H

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a < b ? b : a)

#include "utility.h"

typedef struct {
    int height, width, vmax;
    uint8_t ** pixels;
} image_t;

/* Basic constructor */
image_t * create_image(int height, int width, int vmax);

/* Basic constructor with default vmax = 0 */
image_t * create_image_hw(int height, int width);

/* Copies image */
image_t * copy_image(const image_t * image);

/* Free image */
void delete_image(image_t * image);

/* Gets pixel value at (line, column). Out of bounds errors triggers. */
uint8_t get_pixel_image(const image_t * image, size_t line, size_t column);

/* Sets pixel value at (line, column). If vmax < value, reactualize vmax.
   Out of bounds errors triggers. */
void set_pixel_image(image_t * image, size_t line, size_t column, uint8_t value);

/* Reads image in given file (filepath).
   If error occurs with file not a PGM file or not mode P2 gives NULL. */
image_t * read_image(const char * filepath);

/* Writes image in given file (filepath).
   If error occurs with file gives 0 else gives 1. */
int write_image(const image_t * image, const char * filepath, const char * desc);

/* Adapts contrast in a copied image. */
image_t * adapt_contrast_image(const image_t * image, float k);

 #endif
