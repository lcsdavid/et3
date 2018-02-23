#include "point.h"
#include "segment.h"
#include "rect.h"

int main() {
<<<<<<< HEAD
	point_t* A = create_point(1, 1);
	point_t* B = create_point(1, 3);
	point_t* C = create_point(3, 3);
	point_t* D = create_point(3, 1);
	rect_t* r = create_rect(A, B, C, D);
	if(!r)
		exit(0);
	printf("%lf\n", surface_rect(r));
	display_rect(r);
	point_t* p = create_point(0, 0);
	printf("\n%lf, %lf, %lf, %lf\n", scalar_product(p, r->D, r->A),
		scalar_product(p, r->A, r->B), scalar_product(p, r->B, r->C),
		scalar_product(p, r->C, r->D));
	printf("%d\n", point_in_rect(p, r));
=======
	printf("Hello world!");
>>>>>>> 41e9e815a30e05477251052da9d1ae1ee44dd894
	return 0;
}
