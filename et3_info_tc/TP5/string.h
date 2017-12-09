#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Copy la chaîne de caractère. Attention a free() le résultat une fois utilisé. */
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

void order_str_array(char** array, size_t size);

void display_2Darray_int(int** array, size_t n, size_t m);

int** create_2Darray_int(size_t n, size_t m, int default_value);

void free_2Darray(int** array, size_t n);

int** addition_mtm_2Darray_int(int** arr_a, int** arr_b, size_t n, size_t m);

int** substraction_mtm_2Darray_int(int** arr_a, int** arr_b, size_t n, size_t m);

int** multiplication_mtm_2Darray_int(int** arr_a, int** arr_b, size_t n, size_t m);

int** transpose_2Darray_int(int** array, size_t n, size_t m);

/* Falcultatif: pour répérer les problèmes avec la mémoire */
void out_of_memory(char* context);

#endif
