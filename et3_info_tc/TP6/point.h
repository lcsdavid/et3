#ifndef POINT_H
#define POINT_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	double x, y;
} point_t;

point_t* create_point(double x, double y);

void delete_point(point_t* p);

void display_point(point_t const* p);

double distance_point(point_t const* p1, point_t const* p2);

int equal_point(point_t const* p1, point_t const* p2);

void translate_point(point_t* p, double dx, double dy);

double scalar_product(point_t const* A, point_t const* O, point_t const* B);

#endif
