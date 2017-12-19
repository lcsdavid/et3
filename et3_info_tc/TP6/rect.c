#include "rect.h"

rect_t* create_rect(point_t const* A, point_t const* B, point_t const* C, point_t const* D) {
<<<<<<< HEAD
	if(equal_point(A, B) || equal_point(B, C) || equal_point(C, D) || equal_point(D, A))
=======
	if(equal_point(A, B) || equal_point(B, C) || equal_point(C, D) || equal_point(D, A))
>>>>>>> 41e9e815a30e05477251052da9d1ae1ee44dd894
		return NULL;
	if(scalar_product(A, B, C) != 0 || scalar_product(B, C, D) != 0 || scalar_product(C, D, A) != 0)
		return NULL;
	rect_t* that = malloc(sizeof(rect_t));
	that->A = malloc(sizeof(point_t));
<<<<<<< HEAD
	*that->A = *A;
	that->B = malloc(sizeof(point_t));
	*that->B = *B;
	that->C = malloc(sizeof(point_t));
	*that->C = *C;
	that->D = malloc(sizeof(point_t));
	*that->D = *D;
=======
	that->A = *A;
	that->B = malloc(sizeof(point_t));
	that->B = *B;
	that->C = malloc(sizeof(point_t));
	that->C = *C;
	that->D = malloc(sizeof(point_t));
	that->A = *A;

>>>>>>> 41e9e815a30e05477251052da9d1ae1ee44dd894
	return that;
}

void delete_rect(rect_t* r) {
	delete_point(r->A);
	delete_point(r->B);
	delete_point(r->C);
	delete_point(r->D);
	free(r);
}

<<<<<<< HEAD
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

int equal_rect(rect_t const* r1, rect_t const* r2) {
	if(equal_point(r1->A, r2->A))
		return equal_point(r1->B, r2->B) && equal_point(r1->C, r2->C) && equal_point(r1->D, r2->D);
	if(equal_point(r1->A, r2->B))
		return equal_point(r1->B, r2->C) && equal_point(r1->C, r2->D) && equal_point(r1->D, r2->A);
	if(equal_point(r1->A, r2->C))
		return equal_point(r1->B, r2->D) && equal_point(r1->C, r2->A) && equal_point(r1->D, r2->B);
	if(equal_point(r1->A, r2->D))
		return equal_point(r1->B, r2->A) && equal_point(r1->C, r2->B) && equal_point(r1->D, r2->C);
	return 0;
}

double surface_rect(rect_t const* r) {
	return distance_point(r->A, r->B) * distance_point(r->B, r->C);
}

int point_in_rect(point_t const* p, rect_t const* r) {
	return scalar_product(r->B, r->A, p) >= 0
		&& scalar_product(r->C, r->B, p) >= 0
		&& scalar_product(r->D, r->C, p) >= 0
		&& scalar_product(r->A, r->D, p) >= 0;
}

int disjoint_rect(rect_t const* r1, rect_t const* r2) {
	return !point_in_rect(r1->A, r2) && !point_in_rect(r1->B, r2)
		&& !point_in_rect(r1->C, r2) && !point_in_rect(r1->D, r2)
		&& !point_in_rect(r2->A, r1) && !point_in_rect(r2->B, r1)
		&& !point_in_rect(r2->C, r1) && !point_in_rect(r2->D, r1);
}
=======

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
>>>>>>> 41e9e815a30e05477251052da9d1ae1ee44dd894
