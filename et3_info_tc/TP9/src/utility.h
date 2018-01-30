#ifndef UTILITY_H
#define UTILITY_H

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/stat.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a < b ? b : a)

// Error handling

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

// File parsing

/**
 *  End the line in a file.
 *  @param file
 */
void end_line(FILE * file);

/**
 *  Skip every line which begins by #.
 *  @param file
 */
void skip_comments(FILE * file);

/**
 *  Check if there is data before reach end of file.
 *  @param file
	@return if data return 0 if not 1
 */
int check_eof(FILE * file);

// Display

/**
 *  Formatted output which explains how works application.
 */
void print_help();

/**
 * Create a folder according to the given path.
 * @param filepath
 */
void create_folder(const char * filepath);

#endif
