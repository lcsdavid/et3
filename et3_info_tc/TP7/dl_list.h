#ifndef DL_LIST_H
#define DL_LIST_H

#include <stdlib.h>
#include <assert.h>

#include "dl_cell.h"

typedef struct {
	dl_cell_t* first;
	dl_cell_t* last;
} dl_list_t;

dl_list_t* create_dl_list();

void delete_dl_list(dl_list_t* l);

int is_empty_dl_list(dl_list_t* l);

void push_front_dl_list(dl_list_t* l, dl_cell_t* c);

void push_back_dl_list(dl_list_t* l, dl_cell_t* c);

dl_cell_t* find_dl_list(dl_list_t* l, double value);

#endif
