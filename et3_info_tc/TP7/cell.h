#ifndef CELL_H
#define CELL_H

typedef struct cell_t;

typedef struct {
	double value;
	cell_t* next;
} cell_t;

cell_t* create_cell(double value);

void delete_cell(cell_t* c);

void link_cell(cell_t* c);

void unlink_cell(cell_t* c);

#endif
