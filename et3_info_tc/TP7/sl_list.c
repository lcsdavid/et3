#include "sl_list.h"

sl_list_t* create_sl_list() {
	sl_list_t* that = malloc(sizeof(sl_list_t));
	that->first = NULL;
	return that;
}

void delete_sl_list(sl_list_t* l) {
	free(l);
}

int is_empty_sl_list(sl_list_t* l) {
	if(l->first) // Si l->first non NULL.
		return 0;
	else
		return 1;
}

void push_front_sl_list(sl_list_t* l, sl_cell_t* c) {
	if(l->first) // Si l->first non NULL.
		l->c->next = l->first;
	l->first = c;
}

void push_back_sl_list(sl_list_t* l, sl_cell_t* c) {
	if(l->first) {
		sl_cell_t* current_cell = l->first;
		while(current_cell->next) // Tant que current_cell->next non NULL.
			current_cell = current_cell->next;
		current_cell->next = c;
	}
	l->first = c;
}

sl_cell_t* find_sl_list(sl_list_t* l, double value) {
	if(l->first) {
		sl_cell_t* current_cell = l->first;
		while(current_cell->value != value) {*
			current_cell = current_cell->next;
			if(!current_cell) // Si current_cell NULL.
				break;
		}
		return current_cell;
	}
	return NULL;
}
