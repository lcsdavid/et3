#include "dl_list.h"

dl_list_t* create_dl_list() {
	dl_list_t* that = malloc(sizeof(dl_list_t));
	that->first = NULL;
	that->last = NULL;
	return that;
}

void delete_dl_list(dl_list_t* l) {
	assert(l);	
	free(l);
}

int is_empty_dl_list(dl_list_t* l) {
	assert(l);
	if(l->first || l->last)
		return 0;
	else
		return 1;
}

void push_front_dl_list(dl_list_t* l, dl_cell_t* c) {
	assert(l);
	if(l->first) {
		c->next = l->first;
		c->previous = NULL;
	}
	l->first = c;
}

void push_back_dl_list(dl_list_t* l, dl_cell_t* c) {
	assert(l);
	if(l->last) {
		c->next = NULL;
		c->previous = l->last;
	}
	l->last = c;
}

dl_cell_t* find_dl_list(dl_list_t* l, double value) {
	assert(l);
	if(l->first) {
		dl_cell_t* current_cell = l->first;
		while(current_cell->value != value) {
			current_cell = current_cell->next;
			if(!current_cell)
				break;
		}
		return current_cell;
	}
	return NULL;
}

