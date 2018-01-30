#include <string.h>
#include "image.h"
#include "histogram.h"

int main(int argc, const char ** argv) {
	image_t * image;
	switch(argc) {
		case 1:
			printf("Invalid request.\nTry --help for more help.\n");
			break;
		case 2:
			if(strcmp("--help", argv[1]) == 0)
				print_help();
			else
				printf("Invalid request.\nTry --help for more help.\n");	
			break;
		case 3:
			create_folder("out/");
			char filepath_out[32000] = "out/";
			image = read_image(argv[2]);
			if(!image) return -1;
			if(strcmp("-bw", argv[1]) == 0 || strcmp("--black-n-white", argv[1]) == 0) {
				strcat(strcat(filepath_out, "bw_"), &strrchr(argv[2], '/')[1]);
				grey_to_bw(image);
			} else if(strcmp("-cl", argv[1]) == 0 || strcmp("--closing", argv[1]) == 0) {
				strcat(strcat(filepath_out, "cl_"), &strrchr(argv[2], '/')[1]);
				closing(image);
			} else if(strcmp("-cp", argv[1]) == 0 || strcmp("--copy", argv[1]) == 0) {
				strcat(strcat(filepath_out, "cp_"), &strrchr(argv[2], '/')[1]);
			} else if(strcmp("-d", argv[1]) == 0 || strcmp("--dilation", argv[1]) == 0) {
				strcat(strcat(filepath_out, "d_"), &strrchr(argv[2], '/')[1]);
				dilation(image);
			} else if(strcmp("-e", argv[1]) == 0 || strcmp("--erosion", argv[1]) == 0) {
				strcat(strcat(filepath_out, "e_"), &strrchr(argv[2], '/')[1]);
				erosion(image);
			} else if(strcmp("-h", argv[1]) == 0 || strcmp("--histogram", argv[1]) == 0) {
				strcat(strcat(filepath_out, "h_"), &strrchr(argv[2], '/')[1]);
				histogram_t * histogram = histogram_image(image);
				if(!histogram) return -1;
				write_histogram(histogram, filepath_out);
				delete_image(image);
				break;
			} else if(strcmp("-o", argv[1]) == 0 || strcmp("--opening", argv[1]) == 0) {
				strcat(strcat(filepath_out, "e_"), &strrchr(argv[2], '/')[1]);
				opening(image);
			} else {
				printf("Invalid request.\nTry --help for more help.\n");
				break;
			}
			if(!write_image(image, filepath_out, "")) return -1;;
			delete_image(image);
			break;
		case 4:
			if(strcmp("-ac", argv[1]) == 0 || strcmp("--adapt-contrast", argv[1]) == 0) {
				char filepath_out[32000] = "out/";
				create_folder(filepath_out);
				strcat(strcat(filepath_out, "ac_"), &strrchr(argv[2], '/')[1]);
				image_t * image = read_image(argv[3]);
				if(!image) return -1;
				float k = atof(argv[2]);
				adapt_contrast_image(image, k);
				if(!write_image(image, filepath_out, "")) return -1;;
				delete_image(image);
				break;
			}
			create_folder(argv[3]);
			image = read_image(argv[2]);
			if(!image) return -1;
			if(strcmp("-bw", argv[1]) == 0 || strcmp("--black-n-white", argv[1]) == 0) {
				grey_to_bw(image);
			} else if(strcmp("-cl", argv[1]) == 0 || strcmp("--closing", argv[1]) == 0) {
				closing(image);
			} else if(strcmp("-cp", argv[1]) == 0 || strcmp("--copy", argv[1]) == 0) {
			} else if(strcmp("-d", argv[1]) == 0 || strcmp("--dilation", argv[1]) == 0) {
				dilation(image);
			} else if(strcmp("-e", argv[1]) == 0 || strcmp("--erosion", argv[1]) == 0) {
				erosion(image);
			} else if(strcmp("-h", argv[1]) == 0 || strcmp("--histogram", argv[1]) == 0) {
				histogram_t * histogram = histogram_image(image);
				if(!histogram) return -1;
				write_histogram(histogram, argv[3]);
				delete_image(image);
				break;
			} else if(strcmp("-o", argv[1]) == 0 || strcmp("--opening", argv[1]) == 0) {
				opening(image);
			} else {
				printf("Invalid request.\nTry --help for more help.\n");
				break;
			}
			if(!write_image(image, argv[3], "")) return -1;
			delete_image(image);
			break;
		case 5:
			if(strcmp("-ac", argv[1]) == 0 || strcmp("--adapt-contrast", argv[1]) == 0) {
				create_folder(argv[4]);
				image_t * image = read_image(argv[3]);
				if(!image) return -1;
				float k = atof(argv[2]);
				adapt_contrast_image(image, k);
				if(!write_image(image, argv[4], "")) return -1;
				delete_image(image);
				break;
			}
			printf("Invalid request.\nTry --help for more help.\n");
			break;
		default:
			printf("Invalid request.\nTry --help for more help.\n");
			break;
	}
	return 0;
}
