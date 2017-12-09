#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * str_copy(char* str);

char * read_name();

char * lower_case(char* str);

char * upper_case(char* str);

int letter_to_num(char c);

void append(char** array, char* str, size_t size);

int bigger(char* left, char* right);

int smaller(char* left, char* right);

int compare(char* left, char* right);

void swap_str(char* left, char* right);

void order_str_array(char ** array, size_t size);

void out_of_memory(char* context);

#endif
