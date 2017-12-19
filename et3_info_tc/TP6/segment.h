#ifndef SEGMENT_H
#define SEGMENT_H

#include "point.h"

typedef struct {
	point_t* begin;
	point_t* end;
} segment_t;

segment_t* create_segment(point_t const* begin, point_t const* end);

void delete_segment(segment_t* s);

void display_segment(segment_t const* s);

double lenght_segment(segment_t const* s);

double slope(segment_t const* s);

double intercept(segment_t const* s);

int equal_segment(segment_t const* s1, segment_t const* s2);

int point_on_segment(point_t const* p, segment_t const* s);

point_t* intersect_segment(segment_t const* s1, segment_t const* s2);

#endif
