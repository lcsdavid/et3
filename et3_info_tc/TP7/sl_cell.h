#ifndef SL_CELL_H
#define SL_CELL_H

#include <stdlib.h>
#include <assert.h>

typedef struct sl_cell_t;

typedef struct {
	double value;
	sl_cell_t* next;
} sl_cell_t;

sl_cell_t* create_sl_cell(double value);

void delete_sl_cell(sl_cell_t* c);

void link_sl_cell(sl_cell_t* c);

void unlink_sl_cell(sl_cell_t* c);

#endif
