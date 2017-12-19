#ifndef SL_LIST_H
#define SL_LIST_H

#include "sl_cell.h"

typedef struct {
	sl_cell_t* first;
} sl_list_t;

sl_list_t* create_sl_list();

void delete_sl_list(sl_list_t* l);

int is_empty_sl_list(sl_list_t* l);

void push_front_sl_list(sl_list_t* l);

void push_back_sl_list(sl_list_t* l);

void find_sl_list(sl_list_t* l);

#endif
