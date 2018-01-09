#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	assert(argc > 2);
	float nombre = atof(argv[2]);
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
	}
}
