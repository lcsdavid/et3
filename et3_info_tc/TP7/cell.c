#include "cell.h"

cell_t* create_cell(double value) {
	cell_t* that = malloc(sizeof(cell_t));
	that->value;
	that->next = NULL;
	return that;
}

void delete_cell(cell_t* c) {
	if(c->next)
		delete_cell(c->next);
	free(c);
}

void link_cell(cell_t* c1, cell_t* c2) {
	c1->next = c2;
}

void unlink_cell(cell_t* c) {
	
	c->next = NULL;
}
