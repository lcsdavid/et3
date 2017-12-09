#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

void out_of_memory(char* context);

void free_ptr(void** arr, size_t n);

int digit_number_int(int number);

#endif
