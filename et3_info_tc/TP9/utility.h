#ifndef UTILITY_H
#define UTILITY_H

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a < b ? b : a)

#include <stdio.h>
#include <stdlib.h>

void out_of_memory(const char * context);

void out_of_bounds(const char * context);

/* Special merge_sort algo for gamut array. */
void merge_sort_gamut(uint8_t ** A, size_t n);

/* Special merge algo for gamut array. */
void merge_gamut(uint8_t ** A, size_t left, size_t right, size_t end, uint8_t ** B);

/* Copy array for gamut array */
void copy_array_gamut(uint8_t ** A, uint8_t ** B, size_t n);

#endif
