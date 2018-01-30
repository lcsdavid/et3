#ifndef IMAGE_H
#define IMAGE_H

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


#include "histogram.h"
#include "utility.h"

typedef struct Histogram histogram_t;

/**
 * /struct image_t as dimension (height, width). A max value (vmax). A 2D array (pixels) of pixels value.
 */
typedef struct Image {
    int height, width, vmax;
    uint8_t ** pixels;
} image_t;

/**
 * Basic constructor of image_t.
 * Creates an image of height * width pixels. Pixels set to vmax (white).
 * @param height Dimension of image.
 * @param width Dimension of image.
 * @param vmax Max pixel value (max is 255).
 * @return image_t
 */
image_t * create_image(int height, int width, int vmax);

/**
 * Basic constructor. (calls create_image)
 * With vmax set by default to 255.
 * @param height Dimension of image.
 * @param width Dimension of image.
 * @return image_t
 */
image_t * create_image_hw(int height, int width);

/**
 * Copies image_t in a new image_t.
 * Operation pointer free.
 * @param image to copy.
 * @return image_t copied.
 */
image_t * copy_image(const image_t * image);

/**
 * Delete image_t.
 * @param image to delete.
 */
void delete_image(image_t * image);

/**
 * Get pixel of image_t at line, column position.
 * Out of bounds errors triggers.
 * @param image to look.
 * @param line position.
 * @param column position.
 * @return Pixel value.
 */
uint8_t get_pixel_image(const image_t * image, size_t line, size_t column);

/**
 * Sets pixel value at (line, column).
 * If vmax < value, refresh vmax.
 * Out of bounds errors triggers.
 * @param image to modify.
 * @param line position.
 * @param column position.
 * @param value to assign.
 */
void set_pixel_image(image_t * image, size_t line, size_t column, uint8_t value);

/**
 * Reads image in given file at filepath.
 * @param filepath location of file.
 * @return If file not PGM or not P2 : NULL else image read.
 */
image_t * read_image(const char * filepath);

/**
 * Writes image_t in given file at filepath.
 * @param image image_t to write.
 * @param filepath location of file.
 * @param desc add a description to file.
 * @return If success : 1 else 0;
 */
int write_image(const image_t * image, const char * filepath, const char * desc);

/**
 * Adapts contrast in image.
 * @param image
 * @param k
 * @return Contrasted image.
 */
image_t * adapt_contrast_image(image_t * image, float k);

/**
 * Transforms grey scaled iamge into black and white image.
 * image_t->vmax becomes 1.
 * @param image
 * @return image
 */
image_t * grey_to_bw(image_t * image);

/**
 * Erodes image.
 * @param image
 * @return image
 */
image_t * erosion(image_t * image);

/**
 * Dilates image.
 * @param image
 * @return image
 */
image_t * dilation(image_t * image);

/**
 * Erodes then dilates image.
 * @param image
 * @return image
 */
image_t * opening(image_t * image);

/**
 * Dilates then erodes image.
 * @param image
 * @return image.
 */
image_t * closing(image_t * image);

#endif
