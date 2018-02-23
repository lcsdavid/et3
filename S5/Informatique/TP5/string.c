#include "string.h"

char * string_copy(char* str) {
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
		return string_copy(str_name);
	return string_copy("Entrée non valide.");
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

char** append(char** array, char* str, size_t size) {
	if(size == 0)
		array = malloc(sizeof(char*));
	else
		array = realloc(array, sizeof(char*) * (size + 1));
	if(array == 0)
		out_of_memory("append, malloc on array.");
	array[size] = string_copy(str);
	return array;
}

int bigger(char* left, char* right) {
	size_t size;
	if(strlen(left) > strlen(right))
		size = strlen(left);
	else
		size = strlen(right);
	for(int i = 0; i < size; i++) {
		if(letter_to_num(left[i]) > letter_to_num(right[i]))
			return 1;
		if(letter_to_num(left[i]) < letter_to_num(right[i]))
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

void display_array_string(char ** array, size_t size) {
	for(size_t i = 0; i < size; i++)
			printf("%s\n", array[i]);
}

void sort_array_string(char ** array, size_t size) {
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
