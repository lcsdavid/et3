#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

/* Copy la chaîne de caractère. Attention a free() le résultat une fois utilisé. */
char * string_copy(char* str);

char * read_name();

char * lower_case(char* str);

char * upper_case(char* str);

int letter_to_num(char c);

char** append(char** array, char* str, size_t size);

int bigger(char* left, char* right);

int smaller(char* left, char* right);

int compare(char* left, char* right);

void swap_string(char* left, char* right);

/* Tableau de chaîne de caractère */
void sort_array_string(char** array, size_t size);

void display_array_string(char** array, size_t size);

#endif
