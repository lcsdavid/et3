#ifndef DL_LIST_H
#define DL_LIST_H

#include "dl_cell.h"

typedef struct {
	dl_cell_t* first;
	dl_cell_t* last;
} dl_list_t;

#endif
