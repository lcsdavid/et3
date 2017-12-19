#include "dl_cell.h"

dl_cell_t* create_dl_cell(double value) {
	dl_cell_t* that = malloc(sizeof(dl_cell_t));
	that->value = value;
	that->next = NULL;
	that->previous = NULL;
	return that;
}

dl_cell_t* copy_dl_cell(dl_cell_t* c) {
	dl_cell_t* copy_cell = create_dl_cell(c->value);
	copy_cell->next = c->next;
	copy_cell->previous = c->previous;
	return copy_cell;
}

void delete_dl_cell(dl_cell_t* c) {
	assert(c);
	free(c);
}

void delete_chain_dl_cell(dl_cell_t* c) {
	assert(c);
	if(c->next)
		delete_chain_dl_cell(c->next);
	if(c->previous)
		delete_chain_dl_cell(c->previous);
	delete_dl_cell(c);
}

void link_dl_cell(dl_cell_t* main_cell, dl_cell_t* next_cell, dl_cell_t* previous_cell) {
	assert(main_cell);
	main_cell->next = next_cell;
	main_cell->previous = previous_cell;
}

void unlink_dl_cell(dl_cell_t* c) {
	assert(c);
	c->next = NULL;
	c->previous = NULL;
}
