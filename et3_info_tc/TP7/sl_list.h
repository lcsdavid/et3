#ifndef SL_LIST_H
#define SL_LIST_H

#include <stdlib.h>
#include <assert.h>

#include "sl_cell.h"

typedef struct {
	sl_cell_t* first;
} sl_list_t;

sl_list_t* create_sl_list();

void delete_sl_list(sl_list_t* l);

int is_empty_sl_list(sl_list_t* l);

void push_front_sl_list(sl_list_t* l, sl_cell_t* c);

void push_back_sl_list(sl_list_t* l, sl_cell_t* c);

sl_cell_t* find_sl_list(sl_list_t* l, double value);

sl_list_t* zip_sl_list(sl_list_t* l1, sl_list_t* l2);

sl_cell_t* find_last_sl_list(sl_list_t* l, double value);

sl_list_t* reverse_sl_list(sl_list_t* l);

sl_list_t* filter_sl_list(sl_list_t* l, int *f(double));

#endif
