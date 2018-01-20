#ifndef UTILITY_H
#define UTILITY_H

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a < b ? b : a)

/**
 * Format filepath in function of a given prefix.
 * @param filepath
 * @param prefix
 * @return new_filepath
 */
char * modify_filepath(const char * filepath, const char * prefix);

/**
 * Out of memory error.
 * @param context Can be the function and/or the line which triggered this error.
 */
void out_of_memory(const char * context);

/**
 * Out of bounds error.
 * @param context Can be the function and/or the line which triggered this error.
 */
void out_of_bounds(const char * context);

/**
 *  Formatted output which explains how works application.
 */
void print_help();

#endif
