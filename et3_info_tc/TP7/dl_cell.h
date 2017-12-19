#ifndef DL_CELL_H
#define DL_CELL_H

typedef struct dl_cell_t;

typedef struct {
	double value;
	dl_cell_t* next;
	dl_cell_t* previous;
} dl_cell_t;

dl_cell_t* create_dl_cell(double value);

void delete_dl_cell(dl_cell_t* c);

void delete_chain_dl_cell(dl_cell_t* c)

void link_dl_cell(dl_cell_t* main_cell, dl_cell_t* previous_cell, dl_cell_t* next_cell) ;

void unlink_dl_cell(dl_cell_t* c);

#endif
