/**
 * \file main.c
 * \brief Programme PGM.
 * \author Lucas David
 * \version 1.0
 * \date 19 janvier 2018
 *
 * Programme de maniputlation de fichier PGM.
 */

#include <string.h>
#include "image.h"
#include "histogram.h"

int main(int argc, const char ** argv) {
    if(argc == 1)
        printf("Try --help for help.\n");
    if(argc > 1) {
        if(strcmp("--help", argv[1]) == 0)
            print_help();
        else if(strcmp("-bw", argv[1]) == 0 || strcmp("--black-n-white", argv[1]) == 0) {
            if(argc != 3) {
                printf("Argument -bw, --black-n-white needs only one more argument [FILE].\n");
                printf("Try --help for more help.\n");
                exit(0);
            } else {
				char * filepath = modify_filepath(argv[2], "bw");
                image_t * image = read_image(argv[2]);
                grey_to_bw(image);
                write_image(image, filepath, "");
                delete_image(image);
                free(filepath);
            }
        } else if(strcmp("-cl", argv[1]) == 0 || strcmp("--closing", argv[1]) == 0) {
            if(argc != 3) {
                printf("Argument -cl, --closing needs only one more argument [FILE].\n");
                printf("Try --help for more help.\n");
                exit(0);
            } else {
				char * filepath = modify_filepath(argv[2], "cl");
                image_t * image = read_image(argv[2]);
				if(image->vmax != 1)
                    grey_to_bw(image);
				closing(image);
                write_image(image, filepath, "");
                delete_image(image);
                free(filepath);
            }
        } else if(strcmp("-cp", argv[1]) == 0 || strcmp("--copy", argv[1]) == 0) {
            if(argc != 3) {
                printf("Argument -cp, --copy needs only one more argument [FILE].\n");
                printf("Try --help for more help.\n");
                exit(0);
            } else {
				char * filepath = modify_filepath(argv[2], "cp");
                image_t * image = read_image(argv[2]);
                write_image(image, filepath, "");
                delete_image(image);
                free(filepath);
            }
        } else if(strcmp("-d", argv[1]) == 0 || strcmp("--dilation", argv[1]) == 0) {
            if(argc != 3) {
                printf("Argument -d, --dilation needs only one more argument [FILE].\n");
                printf("Try --help for more help.\n");
                exit(0);
            } else {
				char * filepath = modify_filepath(argv[2], "d");
                image_t * image = read_image(argv[2]);
                if(image->vmax != 1)
                    grey_to_bw(image);
                dilation(image);
                write_image(image, filepath, "");
                delete_image(image);
                free(filepath);
            }
        } else if(strcmp("-e", argv[1]) == 0 || strcmp("--erosion", argv[1]) == 0) {
            if(argc != 3) {
                printf("Argument -e, --erosion needs only one more argument [FILE].\n");
                printf("Try --help for more help.\n");
                exit(0);
            } else {
				char * filepath = modify_filepath(argv[2], "e");
                image_t * image = read_image(argv[2]);
                if(image->vmax != 1)
                    grey_to_bw(image);
                erosion(image);
                write_image(image, filepath, "");
                delete_image(image);
                free(filepath);
            }
        } else if(strcmp("-h", argv[1]) == 0 || strcmp("--histogram", argv[1]) == 0) {
            if(argc != 3) {
                printf("Argument -h, --histogram needs only one more argument [FILE].\n");
                printf("Try --help for more help.\n");
                exit(0);
            } else {
				char * filepath = modify_filepath(argv[2], "h");
                image_t * image = read_image(argv[2]);
                histogram_t * histogram = histogram_image(image);
                delete_image(image);
                write_histogram(histogram, filepath);
                delete_histogram(histogram);
                free(filepath);
            }
        } else if(strcmp("-o", argv[1]) == 0 || strcmp("--opening", argv[1]) == 0) {
            if(argc != 3) {
                printf("Argument -o, --opening needs only one more argument [FILE].\n");
                printf("Try --help for more help.\n");
                exit(0);
            } else {
				char * filepath = modify_filepath(argv[2], "o");
                image_t * image = read_image(argv[2]);
				if(image->vmax != 1)
                    grey_to_bw(image);
				opening(image);
                write_image(image, filepath, "");
                delete_image(image);
                free(filepath);
            }
        } else {
			printf("Invalid request.\n");
			printf("Try --help for more help.\n");	
		}
    } else {
		printf("Invalid request.\n");
		printf("Try --help for more help.\n");	
    }
	return 0;
}
