#ifndef DL_CELL_H
#define DL_CELL_H

#include <stdlib.h>
#include <assert.h>

typedef struct dl_cell dl_cell_t;

typedef struct dl_cell {
	double value;
	dl_cell_t* next;
	dl_cell_t* previous;
} dl_cell_t;

dl_cell_t* create_dl_cell(double value);

dl_cell_t* copy_dl_cell(dl_cell_t* c);

void delete_dl_cell(dl_cell_t* c);

void delete_chain_dl_cell(dl_cell_t* c);

void link_dl_cell(dl_cell_t* main_cell, dl_cell_t* next_cell, dl_cell_t* previous_cell);

void unlink_dl_cell(dl_cell_t* c);

#endif
