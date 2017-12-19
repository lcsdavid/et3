#include "rect.h"

rect_t* create_rect(point_t const* A, point_t const* B, point_t const* C, point_t const* D) {
	if(equal_point(A, B) || equal_point(B, C) || equal_point(C, D) || equal_point(D, A))
		return NULL;
	if(scalar_product(A, B, C) != 0 || scalar_product(B, C, D) != 0 || scalar_product(C, D, A) != 0)
		return NULL;
	rect_t* that = malloc(sizeof(rect_t));
	that->A = malloc(sizeof(point_t));
	that->A = *A;
	that->B = malloc(sizeof(point_t));
	that->B = *B;
	that->C = malloc(sizeof(point_t));
	that->C = *C;
	that->D = malloc(sizeof(point_t));
	that->A = *A;

	return that;
}

void delete_rect(rect_t* r) {
	delete_point(r->A);
	delete_point(r->B);
	delete_point(r->C);
	delete_point(r->D);
	free(r);
}


void display_rect(rect_t const* r) {
	printf("[");	
	display_point(r->A);
	printf(", ");	
	display_point(r->B);
	printf(", ");	
	display_point(r->C);
	printf(", ");		
	display_point(r->D);
	printf("]");
}
