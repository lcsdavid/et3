#ifndef MATRIX_H
#define MATRIX_H

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int** array;
	size_t n, m;
} matrix_t;

matrix_t* create_matrix(size_t n, size_t m);

void delete_matrix(matrix_t *matrix);

void display_matrix(matrix_t *matrix);

int set_value_matrix(matrix_t *matrix, size_t n, size_t m, int value);

#endif
