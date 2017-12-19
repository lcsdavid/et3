#include "point.h"

point_t* create_point(double x, double y) {
	point_t* that = malloc(sizeof(point_t));
	that->x = x;
	that->y = y;
	return that;
}

void delete_point(point_t* p) {
	free(p);
}

void display_point(point_t const* p) {
	printf("(%lf,%lf)", p->x, p->y);
}

double distance_point(point_t const* p1, point_t const* p2) {
	return sqrt((p2->x - p1->x) * (p2->x - p1->x) + (p2->y - p1->y) * (p2->y - p1->y));
}

int equal_point(point_t const* p1, point_t const* p2) {
	return p1->x == p2->x && p1->y == p2->y;
}

void translate_point(point_t* p, double dx, double dy) {
	p->x += dx;
	p->y += dy;
}

double scalar_product(point_t const* A, point_t const* O, point_t const* B) {
	return ((A->x - O->x) * (B->x - O->x) + (A->y - O->y) * (B->y - O->y)) / (distance_point(O,A) * distance_point(O,B));
}

