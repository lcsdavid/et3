#include "sl_cell.h"

sl_cell_t* create_cell(double value) {
	sl_cell_t* that = malloc(sizeof(sl_cell_t));
	that->value;
	that->next = NULL;
	return that;
}

void delete_cell(sl_cell_t* c) {
	assert(c);
	if(c->next)
		delete_cell(c->next);
	free(c);
}

void link_cell(sl_cell_t* c1, sl_cell_t* c2) {
	assert(c1);
	c1->next = c2;
}

void unlink_cell(sl_cell_t* c) {
	assert(c);
	c->next = NULL;
}
