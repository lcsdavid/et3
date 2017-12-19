#ifndef RECT_H
#define RECT_H

#include "point.h"

typedef struct {
	point_t* A;
	point_t* B;
	point_t* C;
	point_t* D;
} rect_t;

rect_t* create_rect(point_t const* A, point_t const* B, point_t const* C, point_t const* D);

void delete_rect(rect_t* r);

void display_rect(rect_t const* r);

int equal_rect(rect_t const* r1, rect_t const* r2);

double surface_rect(rect_t const* r);

int point_in_rect(point_t const* p, rect_t const* r);

int disjoint_rect(rect_t const* r1, rect_t const* r2);

#endif
