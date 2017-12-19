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
	assert(l && c);
	if(l->first) {
		c->next = l->first;
		c->previous = NULL;
	}
	l->first = c;
}

void push_back_dl_list(dl_list_t* l, dl_cell_t* c) {
	assert(l && c);
	if(l->last) {
		c->next = NULL;
		c->previous = l->last;
	}
	l->last = c;
}

dl_cell_t* find_dl_list(dl_list_t* l, double value) {
	assert(l);
	dl_cell_t* current_cell = l->first;
	while(current_cell && current_cell->value != value) {
		current_cell = current_cell->next;
	}
	return current_cell;
}

dl_list_t* zip_dl_list(dl_list_t* l1, dl_list_t* l2) {
	assert(l1 && l2);
	dl_list_t* zip_list = create_dl_list();
	dl_cell_t* current_cell_1 = l1->first;
	dl_cell_t* current_cell_2 = l2->first;
	while (current_cell_1 && current_cell_2) {
		if(current_cell_1) {
			push_back_dl_list(zip_list, current_cell_1);
			current_cell_1 = current_cell_1->next;
		}
		if(current_cell_2) {
			push_back_dl_list(zip_list, current_cell_2);
			current_cell_2 = current_cell_2->next;
		}
	}
	return zip_list;
}

dl_cell_t* find_last_dl_list(dl_list_t* l, double value) {
	assert(l);
	dl_cell_t* current_cell = l->last;
	while(current_cell && current_cell->value != value) {
		current_cell = current_cell->previous;
	}
	return current_cell;
}

dl_list_t* reverse_dl_list(dl_list_t* l) {
	assert(l);
	dl_list_t* reversed_list = create_dl_list();
	dl_cell_t* current_cell = l->first;
	while(current_cell) {
		push_front_dl_list(reversed_list, current_cell);
		current_cell = current_cell->next;
	}
	return reversed_list;
}

dl_list_t* filter_dl_list(dl_list_t* l, int *f(double)) {
	assert(l && f);
	dl_list_t* filtered_list = create_dl_list();
	dl_cell_t* current_cell = l->first;
	while (current_cell) {
		if(f(current_cell->value))
			push_back_dl_list(filtered_list, current_cell);
		current_cell = current_cell->next;
	}
	return filtered_list;
}
