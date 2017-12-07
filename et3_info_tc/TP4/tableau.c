#include "tableau.h"

void string_to_array_int(int* array, char** values, size_t size) {
	for(size_t i = 0; i < size; i++)
		array[i] = atoi(values[i]);
}

void string_to_array_float(float* array, char** values, size_t size)  {
	for(size_t i = 0; i < size; i++)
		array[i] = atof(values[i]);
}

void display_array_int(int* array, size_t size) {
	printf("[");
	for(size_t i = 0; i < size; i++) {
		printf("%d", array[i]);
		if(i != size - 1)
			printf(",");
	}
	printf("]\n");
}

void display_array_float(float* array, size_t size) {
	printf("[");
	for(size_t i = 0; i < size; i++) {
		printf("%f", array[i]);
		if(i != size - 1)
			printf(",");
	}
	printf("]\n");
}

void reset_array_int(int* array, int value, size_t size) {
	for(size_t i = 0; i < size; i++)
		array[i] = value;
}

void reset_array_float(float* array, float value, size_t size) {
	for(size_t i = 0; i < size; i++)
		array[i] = value;
}

int search_in_array_int(int* array, int value, size_t size) {
	for(size_t i = 0; i < size; i++)
		if(array[i] == value)
			return 1;
	return 0;
}

int search_in_array_float(float* array, float value, size_t size) {
	for(size_t i = 0; i < size; i++)
		if(array[i] == value)
			return 1;
	return 0;
}

int occurence_in_array_int(int* array, int value, size_t size) {
	int occ = 0;
	for(size_t i = 0; i < size; i++)
		if(array[i] == value)
			occ++;
	return occ;
}

int occurence_in_array_float(float* array, float value, size_t size) {
	int occ = 0;
	for(size_t i = 0; i < size; i++)
		if(array[i] == value)
			occ++;
	return occ;
}

void rand_array_int(int* array, int min, int max, size_t size) {
	for(size_t i = 0; i < size; i++)
		array[i] = my_rand(min, max);
}

void swap(int * a, int * b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort_int(int* array, size_t size) {
	while(size > 0) {
		for(size_t i = 0; i < size - 1; i++)
			if(array[i] > array[i + 1])
				swap(&array[i], &array[i + 1]);
		size--;
	}
}

int* merge_sorted_int(int* arr_a, int* arr_b, size_t size_a, size_t size_b) {
	// On crée un tableau capable de pouvoir contenir les deux autres tableaux.
	int* merged_arr = malloc(sizeof(int) * (size_a + size_b));
	// La on vas devoir parcourir 3 tableau en même donc on prépare des compteurs
	// pour les deux en paramètre et parcourera le nouveau tableau avec le for.
	size_t a = 0;
	size_t b = 0;
	for(size_t i = 0; i < size_a + size_b; i++) {
		// Il faut vérifié en premier que l'on a pas fini l'un des deux tableau parce
		// que sinon y'a plus qu'à ajouter la suite du tableau qui reste (et parce que sinon on va parcourir des valeurs inexistantes).
		if(a >= size_a) { // arr_a été parcouru dans sa totalité il ne manque plus que arr_b.
			merged_arr[i] = arr_b[b];
			b++;
		}
		else if(b >= size_b) { // arr_b été parcouru dans sa totalité il ne manque plus que arr_a.
			merged_arr[i] = arr_a[a];
			a++;
		}

		// Traitement de départ (à lire plutôt en premier).
		else if(arr_a[a] <= arr_b[b]) {
			// Ici la valeur du tableau a est plus petite donc on l'ajoute au nouveau tableau.
			merged_arr[i] = arr_a[a];
			// On oublie pas d'incrémenter a pour ne pas passer de fois sur arr_a[a].
			a++;
		}
		else {
			// Ici du coup c'est l'inverse.
			merged_arr[i] = arr_b[b];
			b++;
		}
	}
	return merged_arr;
}

int* loto(int min, int max, size_t nb_draw) {
	int* draw = malloc(sizeof(int) * nb_draw);
	for(size_t i = 0; i < nb_draw; i++) {
		do {
			int random_number = my_rand(min, max);
			if(search_in_array_int(draw, random_number, i) == 0) {
				draw[i] = random_number;
				break;
			}
		} while(1);
	}
	return draw;
}
