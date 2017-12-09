#include "matrix.h"

void display_matrix_int(int** matrix, size_t n, size_t m) {
	unsigned int max_digits = digit_number_int(absolute_max_matrix_int(matrix, n, m));
	for(size_t i = 0; i < n; i++) {
		printf("[");
		for(size_t j = 0; j < m; j++) {
			printf("%d", matrix[i][j]);
			unsigned int spaces = max_digits - digit_number_int(matrix[i][j]);
			for(unsigned int d = 0; d < s; d++)
				printf(" ");
			if(j != m - 1)
				printf(", ");
		}
		printf("]\n");
	}
}

unsigned int absolute_max_matrix_int(int** matrix, size_t n, size_t m) {
	int max = 0;
	for(size_t i = 0; i < n; i++)
		for(size_t j = 0; j < m; j++) {
			if(i > 0)
				if(matrix[i][j] > max)
					max = matrix[i][j];
			else
				if(-matrix[i][j] > max)
					max = -matrix[i][j];
		}
	}
	return max;
}

int** create_matrix_int(size_t n, size_t m, int default_value) {
	int** mat_result = malloc(sizeof(int*) * n);
	if(!mat_result)
		out_of_memory("create_matrix_int, malloc on mat_result.");
	for(size_t i = 0; i < n; i++) {
    mat_result[i] = malloc(sizeof(int) * m);
		if(!mat_result[i])
			out_of_memory("create_matrix_int, malloc on mat_result[i].");
		for(size_t j = 0; j < m; j++)
			mat_result[i][j] = default_value;
	}
	return mat_result;
}

int** addition_matrix_int(int** mat_a, int** mat_b, size_t n, size_t m) {
	int** mat_result = malloc(sizeof(int*) * n);
	if(!mat_result)
		out_of_memory("addition_matrix_int, malloc on mat_result.");
	for(size_t i = 0; i < n; i++) {
		mat_result[i] = malloc(sizeof(int) * m);
		if(!mat_result[i])
			out_of_memory("addition_matrix_int, malloc on mat_result[i].");
		for(size_t j = 0; j < m; j++)
			mat_result[i][j] = mat_a[i][j] + mat_b[i][j];
	}
	return mat_result;
}

int** substraction_matrix_int(int** mat_a, int** mat_b, size_t n, size_t m) {
	int** mat_result = malloc(sizeof(int*) * n);
	if(!mat_result)
		out_of_memory("substraction_matrix_int, malloc on mat_result.");
	for(size_t i = 0; i < n; i++) {
		mat_result[i] = malloc(sizeof(int) * m);
		if(!mat_result[i])
			out_of_memory("substraction_matrix_int, malloc on mat_result[i].");
		for(size_t j = 0; j < m; j++)
			mat_result[i][j] = mat_a[i][j] - mat_b[i][j];
	}
	return mat_result;
}

int** hadamard_product_matrix_int(int** mat_a, int** mat_b, size_t n, size_t m) {
	int** mat_result = malloc(sizeof(int*) * n);
	if(!mat_result)
		out_of_memory("hadamard_product_matrix_int, malloc on mat_result.");
	for(size_t i = 0; i < n; i++) {
		mat_result[i] = malloc(sizeof(int) * m);
		if(!mat_result[i])
			out_of_memory("hadamard_product_matrix_int, malloc on mat_result[i].");
		for(size_t j = 0; j < m; j++)
			mat_result[i][j] = mat_a[i][j] * mat_b[i][j];
	}
	return mat_result;
}

int** transpose_2Darray_int(int** array, size_t n, size_t m) {
	int** result = malloc(sizeof(int*) * m);
	if(!result)
		out_of_memory("addition_2Darray_int, malloc on result.");
	for(size_t i = 0; i < m; i++) {
		result[i] = malloc(sizeof(int) * n);
		if(!result[i])
			out_of_memory("addition_2Darray_int, malloc on result[i].");
		for(size_t j = 0; j < n; j++)
			result[i][j] = array[j][i];
	}
	return result;
}

int* linesum_matrix_int(int** array, size_t n, size_t m) {
	int* result = malloc(sizeof(int) * m);
	if(!result)
		out_of_memory("linesum_2Darray_int, malloc on result.");
	for(size_t j = 0; j < m; j++) {
		result[j] = 0;
		for(size_t i = 0; i < m; i++)
			result[j] += array[i][j];
	}
	return result;
}

int* columnsum_matrix_int(int** array, size_t n, size_t m) {
	int* result = malloc(sizeof(int) * n);
	if(!result)
		out_of_memory("columnsum_2Darray_int, malloc on result.");
	for(size_t i = 0; i < n; i++) {
		result[i] = 0;
		for(size_t j = 0; j < m; i++)
			result[i] += array[i][j];
	}
	return result;
}

int** product_matrix_int(int** arr_a, int** arr_b, size_t n, size_t m, size_t p) {
	int** result = malloc(sizeof(int*) * p);
	if(!result)
		out_of_memory("multiplication_2Darray_int, malloc on result.");
	for(size_t i = 0; i < n; i++) {
		result[i] = malloc(sizeof(int) * m);
		if(!result[i])
			out_of_memory("multiplication_2Darray_int, malloc on result[i].");
			for(size_t j = 0; j < m; j++)
				for(size_t k = 0; k < n; k++)
					result[i][j] = arr_a[i][k] * arr_b[k][j];
	}
  return result;
}
