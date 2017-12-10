#include "matrix.h"

void display_matrix_int(int **matrix, size_t n, size_t m) {
    unsigned int max_digits = digit_number_int(absolute_max_matrix_int(matrix, n, m));
    for (size_t i = 0; i < n; i++) {
        printf("[");
        for (size_t j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
            unsigned int span = max_digits - digit_number_int(matrix[i][j]);
            for (unsigned int d = 0; d < span; d++)
                printf(" ");
            if (j != m - 1)
                printf(", ");
        }
        printf("]\n");
    }
}

unsigned int absolute_max_matrix_int(int **matrix, size_t n, size_t m) {
    int max = 0;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            if (matrix[i][j] > 0) {
                if (matrix[i][j] > max)
                    max = matrix[i][j];
            } else {
                if (-matrix[i][j] > max)
                    max = -matrix[i][j];
            }
        }
    }
    return max;
}

int **create_matrix_int(size_t n, size_t m, int default_value) {
    int **result_mat = malloc(sizeof(int *) * n);
    if (!result_mat)
        out_of_memory("create_matrix_int, malloc on mat_result.");
    for (size_t i = 0; i < n; i++) {
        result_mat[i] = malloc(sizeof(int) * m);
        if (!result_mat[i])
            out_of_memory("create_matrix_int, malloc on mat_result[i].");
        for (size_t j = 0; j < m; j++)
            result_mat[i][j] = default_value;
    }
    return result_mat;
}

int **addition_matrix_int(int **mat_a, int **mat_b, size_t n, size_t m) {
    int **result_mat = create_matrix_int(n, m, 0);
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            result_mat[i][j] = mat_a[i][j] + mat_b[i][j];
    return result_mat;
}

int **substraction_matrix_int(int **mat_a, int **mat_b, size_t n, size_t m) {
    int **result_mat = create_matrix_int(n, m, 0);
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            result_mat[i][j] = mat_a[i][j] - mat_b[i][j];
    return result_mat;
}

int **hadamard_product_matrix_int(int **mat_a, int **mat_b, size_t n, size_t m) {
    int **result_mat = create_matrix_int(n, m, 0);
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            result_mat[i][j] = mat_a[i][j] * mat_b[i][j];
    return result_mat;
}

int **transpose_2Darray_int(int **array, size_t n, size_t m) {
    int **result_mat = create_matrix_int(n, m, 0);
    for (size_t i = 0; i < m; i++)
        for (size_t j = 0; j < n; j++)
            result_mat[i][j] = array[j][i];
    return result_mat;
}

int *linesum_matrix_int(int **array, size_t n, size_t m) {
    int *result_arr = malloc(sizeof(int) * m);
    if (!result_arr)
        out_of_memory("linesum_2Darray_int, malloc on result.");
    for (size_t j = 0; j < m; j++) {
        result_arr[j] = 0;
        for (size_t i = 0; i < m; i++)
            result_arr[j] += array[i][j];
    }
    return result_arr;
}

int *columnsum_matrix_int(int **array, size_t n, size_t m) {
    int *result_arr = malloc(sizeof(int) * n);
    if (!result_arr)
        out_of_memory("columnsum_2Darray_int, malloc on result.");
    for (size_t i = 0; i < n; i++) {
        result_arr[i] = 0;
        for (size_t j = 0; j < m; i++)
            result_arr[i] += array[i][j];
    }
    return result_arr;
}

int **product_matrix_int(int **arr_a, int **arr_b, size_t n, size_t m, size_t p) {
    int **result_mat = create_matrix_int(n, p, 0);
    for (size_t k = 0; k < m; k++)
        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < p; j++)
                result_mat[i][j] += arr_a[i][k] * arr_b[k][j];
    return result_mat;
}
