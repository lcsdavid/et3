#ifndef UTILITY_H
#define UTILITY_H

#include <string.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a < b ? b : a)


#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void out_of_memory(const char * context);

void out_of_bounds(const char * context);

char * modify_filepath(const char * filepath, const char * prefix);

#endif
