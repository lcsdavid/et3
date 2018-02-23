#include <stdlib.h>
#include <stdio.h>

#include "string.h"
#include "matrix.h"
#include "utils.h"

int main(int argc, char **argv) {
	// 1.1
	/* char* str_name = read_name();
	printf("Your name is: %s\n", str_name);

	// 1.2
	char* str_modified_name = lower_case(str_name);
	printf("Lowered: %s\n", str_modified_name);
	free(str_modified_name);

	// 1.3
	str_modified_name = upper_case(str_name);
	printf("Uppered: %s\n", str_modified_name);
	free(str_modified_name);
	free(str_name);
	// 1.4
	printf("%c gives %d\n", 'a', letter_to_num('a'));

	// 1.5
	char** name_list = NULL;
	for(size_t size = 0; size < 5; size++) {
		name_list = append(name_list, read_name(), size);
	}
	printf("Unsorted list: \n");
	display_array_string(name_list, 5);

	// 2. (sort_array_string utilise les toutes les fonctions de l'exo)
	sort_array_string(name_list, 5);
	printf("\nSorted list: \n");
	display_array_string(name_list, 5);*/

	// 3.2
	int** identity = create_matrix_int(3, 3, 0);
	// 3.1
	for(size_t i = 0; i < 3; i++)
		for(size_t j = 0; j < 3; j++)
		 if(i == j)
			identity[i][j] = 1;
	display_matrix_int(identity, 3, 3);
	// flemme de tester tout dans le main


	// 4
	int** mat = create_matrix_int(3, 3, 5);
	printf("\n");
	display_matrix_int(mat, 3, 3);
	mat = product_matrix_int(identity, mat, 3, 3, 3);
	printf("\n");
	display_matrix_int(mat, 3, 3);

	return 0;
}
