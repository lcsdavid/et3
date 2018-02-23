#include "utils.h"

/* Falcultatif: pour répérer les problèmes avec la mémoire */
void out_of_memory(char *context) {
    printf("Out Of Memory: At function %s\n. Exiting...\n", context);
    exit(0);
}

void free_ptr(void **arr, size_t n) {
    for (size_t i = 0; i < n; i++)
        free(arr[i]);
    free(arr);
}

int digit_number_int(int number) {
    int digits = 1;
    while (number / 10 != 0) {
        digits++;
        number /= 10;
    }
    return digits;
}
