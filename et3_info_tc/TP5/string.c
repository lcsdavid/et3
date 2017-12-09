#include "string.h"

char * str_copy(char* str) {
	size_t size = strlen(str);
	char* str_copy = malloc(sizeof(char) * size);
	if(str_copy == NULL)
		out_of_memory("str_copy, malloc on str_copy.");
	for(size_t i = 0; i < size; i++)
		str_copy[i] = str[i];
	return str_copy;
}

char * read_name() {
	char str_name[256];
	printf("Entrez votre nom: ");
	if(scanf("%s", str_name))
		return str_copy(str_name);
	return str_copy("Entrée non valide.");
}

char * lower_case(char* str) {
	size_t size = strlen(str);
	char* str_lowered_copy = malloc(sizeof(char) * size);
	if(str_lowered_copy == NULL)
		out_of_memory("lower_case, malloc on str_lowered_copy.");
	for(size_t i = 0; i < size; i++) {
		if(str[i] >= 'A' && str[i] <= 'Z')
			str_lowered_copy[i] = str[i] + 'a' - 'A';
		else
			str_lowered_copy[i] = str[i];
	}
	return str_lowered_copy;
}

char * upper_case(char* str) {
	size_t size = strlen(str);
	char* str_uppered_copy = malloc(sizeof(char) * size);
	if(str_uppered_copy == NULL)
		out_of_memory("upper_case, malloc on str_uppered_copy.");
	for(size_t i = 0; i < size; i++) {
		if(str[i] >= 'a' && str[i] <= 'z')
			str_uppered_copy[i] = str[i] + 'A' - 'a';
		else
			str_uppered_copy[i] = str[i];
	}
	return str_uppered_copy;
}

int letter_to_num(char c) {
	if(c >= 'a' && c <= 'z')
		return (int)((c - 'a') % 26 + 1);
	if(c >= 'A' && c <= 'Z')
		return (int)((c - 'A') % 26 + 1);
	return -1;
}

void append(char** array, char* str, size_t size) {
	char** buffer = realloc(array, sizeof(char*) * (size + 1));
	if(buffer == NULL)
		out_of_memory("append, malloc on buffer.");
	for(int i = 0; i < size; i++)
		buffer[i] = array[i];
	buffer[size] = str_copy(str);
	free(array);
	array = buffer;
}

int bigger(char* left, char* right) {
	size_t size;
	if(strlen(left) > strlen(right))
		size = strlen(left);
	else
		size = strlen(right);
	for(int i = 0; i < size; i++) {
		if(left[i] > right[i])
			return 1;
		if(left[i] < right[i])
			return 0;
	}
	return strlen(left) > strlen(right);
}

int smaller(char* left, char* right) {
	return !bigger(left, right);
}

int compare(char* left, char* right) {
	if(bigger(left, right))
		return 1;
	else if(smaller(left, right))
		return -1;
	else
		return 0;
}

void swap_str(char* left, char* right) {
	char* buffer = left;
	left = right;
	right = buffer;
}

void order_str_array(char ** array, size_t size) {
	char* buffer;
	for(int i = 0; i < size; i++) {
		buffer = array[i];
		int j = i;
		while(j > 0 && bigger(array[j - 1],buffer)) {
			array[j] = array[j - 1];
			j--;
		}
		array[j] = buffer;
	}
}

void display_2Darray_int(int** array, size_t n, size_t m) {
	for(size_t i = 0; i < n; i++) {
		printf("[");
		for(size_t j = 0; i < m; j++) {
			printf("%d", array[i][j]);
			if(j != m - 1)
				printf(", ");
		}
		printf("]\n");
	}
}

int** create_2Darray_int(size_t n, size_t m, int default_value) {
	int** result = malloc(sizeof(int) * n);
	if(!result)
		out_of_memory("create_2Darray_int, malloc on result.");
	for(size_t i = 0; i < n; i++) {
		if(!result[i])
			out_of_memory("create_2Darray_int, malloc on result[i].");
		for(size_t j = 0; i < m; j++)
			result[i][j] = default_value;
	}
	return result;
}

void free_2Darray(int** array, size_t n) {
	for(size_t i = 0; i < n; i++)
		free(array[i]);
	free(array);
}

int** addition_mtm_2Darray_int(int** arr_a, int** arr_b, size_t n, size_t m) {
	int** result = malloc(sizeof(int) * n);
	if(!result)
		out_of_memory("addition_2Darray_int, malloc on result.");
	for(size_t i = 0; i < n; i++) {
		result[i] = malloc(sizeof(int) * m);
		if(!result[i])
			out_of_memory("addition_2Darray_int, malloc on result[i].");
		for(size_t j = 0; j < m; j++)
			result[i][j] = arr_a[i][j] + arr_b[i][j];
	}
	return result;
}

int** substraction_mtm_2Darray_int(int** arr_a, int** arr_b, size_t n, size_t m) {
	int** result = malloc(sizeof(int) * n);
	if(!result)
		out_of_memory("addition_2Darray_int, malloc on result.");
	for(size_t i = 0; i < n; i++) {
		result[i] = malloc(sizeof(int) * m);
		if(!result[i])
			out_of_memory("addition_2Darray_int, malloc on result[i].");
		for(size_t j = 0; j < m; j++)
			result[i][j] = arr_a[i][j] - arr_b[i][j];
	}
	return result;
}

int** multiplication_mtm_2Darray_int(int** arr_a, int** arr_b, size_t n, size_t m) {
	int** result = malloc(sizeof(int) * n);
	if(!result)
		out_of_memory("addition_2Darray_int, malloc on result.");
	for(size_t i = 0; i < n; i++) {
		result[i] = malloc(sizeof(int) * m);
		if(!result[i])
			out_of_memory("addition_2Darray_int, malloc on result[i].");
		for(size_t j = 0; j < m; j++)
			result[i][j] = arr_a[i][j] * arr_b[i][j];
	}
	return result;
}

int** transpose_2Darray_int(int** array, size_t n, size_t m) {
	int** result = malloc(sizeof(int) * m);
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

int* linesum_2Darray_int(int** array, size_t n, size_t m) {
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

int* columnsum_2Darray_int(int** array, size_t n, size_t m) {
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

int** multiplication_2Darray_int(int** arr_a, int** arr_b, size_t n, size_t m, size_t p) {
	int* result = malloc(sizeof(int) * p);
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
}


/* Falcultatif: pour répérer les problèmes avec la mémoire */
void out_of_memory(char* context) {
	printf("Out Of Memory: At function %s\n. Exiting...\n",context);
	exit(0);
}
