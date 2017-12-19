#include "dl_cell.h"

dl_cell_t* create_dl_cell(double value) {
	dl_cell_t* that = malloc(sizeof(dl_cell_t));
	that->value = value;
	that->next = NULL;
	that->previous = NULL;
	return that;
}

void delete_dl_cell(dl_cell_t* c) {
	assert(c);
	free(c);
}

void delete_chain_dl_cell(dl_cell_t* c) {
	assert(c);
	free(c);
}

void link_dl_cell(dl_cell_t* main_cell, dl_cell_t* previous_cell, dl_cell_t* next_cell);

void unlink_dl_cell(dl_cell_t* c);

