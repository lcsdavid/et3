#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

void display_matrix_int(int **array, size_t n, size_t m);

unsigned int absolute_max_matrix_int(int **matrix, size_t n, size_t m);

int **create_matrix_int(size_t n, size_t m, int default_value);

int **addition_matrix_int(int **arr_a, int **arr_b, size_t n, size_t m);

int **substraction_matrix_int(int **arr_a, int **arr_b, size_t n, size_t m);

int **hadamard_product_matrix_int(int **arr_a, int **arr_b, size_t n, size_t m);

int **transpose_matrix_int(int **array, size_t n, size_t m);

int *linesum_matrix_int(int **array, size_t n, size_t m);

int *columnsum_matrix_int(int **array, size_t n, size_t m);

int **product_matrix_int(int **arr_a, int **arr_b, size_t n, size_t m, size_t p);


#endif
