#include "sl_list.h"

sl_list_t* create_sl_list() {
	sl_list_t* that = malloc(sizeof(sl_list_t));
	that->first = NULL;
	return that;
}

void delete_sl_list(sl_list_t* l) {
	assert(l);
	free(l);
}

int is_empty_sl_list(sl_list_t* l) {
	assert(l);
	if(l->first)
		return 0;
	else
		return 1;
}

void push_front_sl_list(sl_list_t* l, sl_cell_t* c) {
	assert(l);
	if(l->first)
		c->next = l->first;
	l->first = c;
}

void push_back_sl_list(sl_list_t* l, sl_cell_t* c) {
	assert(l);
	if(l->first) {
		sl_cell_t* current_cell = l->first;
		while(current_cell->next)
			current_cell = current_cell->next;
		current_cell->next = c;
	}
	l->first = c;
}

sl_cell_t* find_sl_list(sl_list_t* l, double value) {
	assert(l);
	if(l->first) {
		sl_cell_t* current_cell = l->first;
		while(current_cell->value != value) {
			current_cell = current_cell->next;
			if(!current_cell)
				break;
		}
		return current_cell;
	}
	return NULL;
}
