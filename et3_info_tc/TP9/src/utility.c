#include "utility.h"

void out_of_memory(const char * context) {
    printf("Out of memory or bad alloc. (%s)\nexiting...\n", context);
	exit(EXIT_FAILURE);
}

void out_of_bounds(const char * context) {
    printf("Out of bounds. (%s)\nexiting...\n", context);
	exit(EXIT_FAILURE);
}


void end_line(FILE * file) {
	assert(file);
	while(fgetc(file) != '\n');
}

void skip_comments(FILE * file) {
	assert(file);
	int c;
	while((c = fgetc(file)) == '#')
		end_line(file);
	ungetc(c, file);
}

int check_eof(FILE * file) {
	int c = 0;
	while(!feof(file)) {
		c = fgetc(file);
		if(isdigit(c)) {
			printf("\n%c\n", c);
			return 0;
		}
	}
	return 1;
}


void print_help() {
    printf("pgm 1.1 (amd64)\n");
    printf("Usage: pgm [COMMAND] ... [FILE_IN] ([FILE_OUT])\n");
    printf("pgm proposes different manipulations with .pgm files.\n\n");

	printf("  -ac, --adapt-contrast  adapt contrast with given [VALUE] on image [FILE]\n");
    printf("  -bw, --black-n-white   tranform grey image to black and white image\n");
    printf("  -cl, --closing         dilate then erode image [FILE]\n");
    printf("  -cp, --copy            copy image [FILE]\n");
    printf("  -d,  --dilation        dilate image [FILE], if image is not black and white but in grey scale applies -bw\n");
    printf("  -e,  --erosion         erode image [FILE], if image is not black and white but in grey scale applies -bw\n");
    printf("  -h,  --histogram       create an histogram of image [FILE]\n");
    printf("  -o,  --opening         erode then dilate image [FILE]\n\n");

    printf("       --help  display this help and exit\n\n");
	
	printf(" By default files are stored in out folder.\n");
}

void create_folder(const char * filepath) {
	size_t len = strlen(filepath);
	size_t index = 0;
	for(size_t i = 0; i < len; i++) {
		if(filepath[i] == '/' || filepath[i] == '\\')
			index = i;
	}
	char dirpath[32000] = "";
	memcpy(dirpath, filepath, index);	
	char buffer[32000] = "";
	for(size_t i = 0; i < len; i++) {
		memcpy(buffer, dirpath, i + 1);
		if(dirpath[i + 1] == '/' || dirpath[i + 1] == '\\' || dirpath[i + 1] == '\0') {
			#ifdef _WIN32
				mkdir(buffer);
			#else
				#ifdef unix
					mkdir(buffer, 0777);
				#endif
			#endif
		}
	}	
}


