#include "matrix.h"

matrix_t* create_matrix(size_t n, size_t m) {
	matrix_t* that = malloc(sizeof(matrix_t));
	that->array = malloc(n * sizeof(int*));
	if(!that->array)
		exit(1);
	for(size_t i = 0; i < n; i++) {
		that->array[i] = malloc(m * sizeof(int));
		if(!that->array[i])
			exit(1);
		for(size_t j = 0; j < m; j++)
		 	that->array[i][j] = 0;
	}
	that->n = n;
	that->m = m;
	return that;
}

void delete_matrix(matrix_t *matrix) {
	for(size_t i = 0; i < matrix->n; i++)
		free(matrix->array[i]);
	free(matrix->array);
	free(matrix);
}

void display_matrix(matrix_t *matrix) {
	printf("[");
	for(size_t i = 0; i < matrix->n; i++) {
		if(i != 0)
				printf(" ");
		printf("[");
		for(size_t j = 0; j < matrix->m; j++)
		 	printf("%d ", matrix->array[i][j]);
		if(i + 1 == matrix->n)
			printf("]]");
		else
			printf("]\n");
	}
}

int set_value_matrix(matrix_t* matrix, size_t n, size_t m, int value) {
	if(matrix->n < n + 1 || matrix->n < m + 1)
		return 0;
	matrix->array[n][m] = value;
	return 1;
}
