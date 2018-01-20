#include "utility.h"

char * modify_filepath(const char * filepath, const char * prefix) {
    assert(filepath && prefix);
    char new_filepath[64] = "out/";
    strcat(new_filepath, prefix);
    strcat(new_filepath, "_");
    size_t beg = 0;
    size_t size = strlen(filepath);
    for(size_t i = beg; i < size; i++) {
        if(filepath[i] == '\\' || filepath[i] == '/')
            beg = i + 1;
        else
            new_filepath[strlen(prefix) + 5 - beg + i] = filepath[i];
    }
    char * buffer = malloc(sizeof(char) * 64);
    strcpy(buffer, new_filepath);
    return buffer;
}

void out_of_memory(const char * context) {
    printf("Out of memory or bad alloc. (%s)\nexiting...\n", context);
	exit(EXIT_FAILURE);
}

void out_of_bounds(const char * context) {
    printf("Out of bounds. (%s)\nexiting...\n", context);
	exit(EXIT_FAILURE);
}

void print_help() {
    printf("pgm 1.0 (amd64)\n");
    printf("Usage: pgm [COMMAND] [FILE]\n");
    printf("pgm proposes different manipulations with .pgm files.\n\n");

    printf("  -bw, --black-n-white  tranform grey image to black and white image\n");
    printf("  -cl, --closing        dilates then erodes image [FILE]\n");
    printf("  -cp, --copy           copy image [FILE]\n");
    printf("  -d,  --dilation       dilate image [FILE], if image is not black and white but in grey scale applies -bw\n");
    printf("  -e,  --erosion        erode image [FILE], if image is not black and white but in grey scale applies -bw\n");
    printf("  -h,  --histogram      create an histogram of image [FILE]\n");
    printf("  -o,  --opening        erodes then dilates image [FILE]\n\n");

    printf("       --help  display this help and exit\n\n");
	
	printf(" All files are stored in out folder.\n");
    printf(" This folder MUST exist!\n");
	exit(0);
}