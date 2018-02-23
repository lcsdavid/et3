#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

void readMatrix(char* filename, matrix_t* m) {
	FILE* f = fopen(filename, "r");
	if(!f)
		exit(1);
	size_t i = 0;
	size_t j = 0;
	int value = 0.f;
	do {
		fscanf(f, "%lu,%lu %d;", &i, &j, &value);
		set_value_matrix(m, i, j, value);
	} while(!feof(f));
	fclose(f);
}

int main(int argc, char** argv) {
	assert(argc > 2);
	/*float nombre = atof(argv[2]);
	switch (atoi(argv[1])) {
		case 2:
			assert(argc > 3);
			FILE* f = fopen(argv[3], "w");
			fprintf(f, "%.2f ", nombre);
			fclose(f);
			break;
		case 3:
			assert(argc > 4);
			FILE* ff = fopen(argv[4], "a+");
			FILE* of = fopen(argv[3], "r");
			fprintf(ff, " %f", nombre);
			if(of) {
				fscanf(of, "%.2f ", &nombre);
				fprintf(ff, "%.2f ", nombre);
				fclose(of);
			}
			fclose(ff);
			break;
		default:
			break;
	}*/
	size_t size = atoi(argv[1]);
	matrix_t* mat = create_matrix(size, size);
	readMatrix(argv[2], mat);
	display_matrix(mat);
}
