#include "segment.h"

segment_t* create_segment(point_t const* begin, point_t const* end) {
	segment_t* that = malloc(sizeof(segment_t));
	that->begin = malloc(sizeof(point_t));
	*that->begin = *begin;
	that->end = malloc(sizeof(point_t));
	*that->end = *end;
	return that;
}

void delete_segment(segment_t* s) {
	delete_point(s->begin);
	delete_point(s->end);
	free(s);
}

void display_segment(segment_t const* s) {
	printf("[");
	display_point(s->begin);
	display_point(s->end);
	printf("]");
}

double lenght_segment(segment_t const* s) {
	return distance_point(s->begin, s->end);
}

int equal_segment(segment_t const* s1, segment_t const* s2) {
	return equal_point(s1->begin, s2->begin) && equal_point(s1->end, s2->end);
}

int point_on_segment(point_t const* p, segment_t const* s) {
	if(slope(s) * p->x + intercept(s) == p->y)
		if(distance_point(p, s->begin) <= lenght_segment(s) && distance_point(p, s->begin) <= lenght_segment(s))
			return 1;
	return 0;
}

double slope(segment_t const* s) {
	return (s->end->y - s->begin->y) / (s->end->x - s->begin->x);
}

double intercept(segment_t const* s) {
	return -slope(s) * s->begin->x / s->begin->y;
}

point_t* intersect_segment(segment_t const* s1, segment_t const* s2) {
	// Cas segment 1 et 2 sont des points.
	if(lenght_segment(s1) == 0 && lenght_segment(s2) == 0) {
		if(equal_point(s1->begin, s2->begin))
			return create_point(s1->begin->x, s1->begin->y);
		return NULL;
	}
	// Cas segment 1 est un point.
	if(lenght_segment(s1) == 0) { // Segment 1 = point
		if(point_on_segment(s1->begin, s2))
			return create_point(s1->begin->x, s1->begin->y);
		return NULL;	
	}
	// Cas segment 2 est un point.
	if(lenght_segment(s2) == 0) { // Segment 2 = point
		if(point_on_segment(s2->begin, s1))
			return create_point(s2->begin->x, s2->begin->y);
		return NULL;
	}
	// Segment parralèle (+ segments superposés).
	double a1 = slope(s1);
	double a2 = slope(s2);
	if(a1 == a2)
		return NULL;
	
	// Cas quelconque.
	double b1 = intercept(s1);
	double b2 = intercept(s2);
	point_t* inter = create_point((b2 - b1) / (a2 - a1), a1 * (b2 - b1) / (a2 - a1) + b1);
	if(point_on_segment(inter, s1) && point_on_segment(inter, s2))
		return inter;
	delete_point(inter);
	return NULL;	
}


