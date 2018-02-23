#ifndef TABLEAU_H
#define TABLEAU_H

#include <stdio.h>
#include <stdlib.h>

#include "rand.h"

/** Conversion d'une chaîne de caractère en tableau d'entier.
  * On suppose que la chaîne de caractère ne contient que des nombres.
  */
void string_to_array_int(int* array, char** values, size_t size);

/** Conversion d'une chaîne de caractère en tableau de flottant.
  * On suppose que la chaîne de caractère ne contient que des nombres.
  */
void string_to_array_float(float* array, char** values, size_t size);

/* Va afficher la totalité du tableau d'entier: array. */
void display_array_int(int* array, size_t size);

/* Va afficher la totalité du tableau d'entier: array. */
void display_array_float(float* array, size_t size);

void reset_array_int(int* array, int value, size_t size);

void reset_array_float(float* array, float value, size_t size);

int search_in_array_int(int* array, int value, size_t size);

int search_in_array_float(float* array, float value, size_t size);

int occurence_in_array_int(int* array, int value, size_t size);

int occurence_in_array_float(float* array, float value, size_t size);

void rand_array_int(int* array, int min, int max, size_t size);

void swap(int* a, int* b);

void bubble_sort_int(int* array, size_t size);

int* merge_sorted_int(int* arr_a, int* arr_b, size_t size_a, size_t size_b);

int* loto(int min, int max, size_t nb_draw);

#endif
