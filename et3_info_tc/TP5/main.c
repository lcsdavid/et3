#include <stdio.h>

#include "string.h"

int main(int argc, char **argv) {
	// 1.1
	char* str_name = read_name();
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

	return 0;
}
