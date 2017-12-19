#include "sl_cell.h"

sl_cell_t* create_cell(double value) {
	sl_cell_t* that = malloc(sizeof(sl_cell_t));
	that->value;
	that->next = NULL;
	return that;
}

void delete_sl_cell(sl_cell_t* c) {
	assert(c);
	free(c);
}

void delete_chain_sl_cell(sl_cell_t* c) {
	assert(c);
	if(c->next)
		delete_cell(c->next);
	delete_sl_cell(c);
}

void link_cell(sl_cell_t* main_cell, sl_cell_t* next_cell) {
	assert(main_cell);
	main_cell->next = next_cell;
}

void unlink_cell(sl_cell_t* c) {
	assert(c);
	c->next = NULL;
}
