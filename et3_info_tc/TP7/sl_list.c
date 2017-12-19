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

sl_list_t* zip_sl_list(sl_list_t* l1, sl_list_t* l2) {
	assert(l1 && l2);
	sl_list_t* zip_list = create_sl_list();
	list_push_front(zip_list, copy_sl_cell(l1->first));
	list_push_back(zip_list, copy_sl_cell(l2->first));
	sl_cell_t* current_cell_1 = l1->first;
	sl_cell_t* current_cell_2 = l2->first;
	while(1) {
		if(!current_cell_1->next && !current_cell_2->next)
			break;
		if(current_cell_1->next) {
			current_cell_1 = current_cell_1->next;
			list_push_back(zip_list, copy_sl_cell(current_cell_1));
		}
		if(current_cell_2->next) {
			current_cell_2 = current_cell_2->next;
			list_push_back(zip_list, copy_sl_cell(current_cell_2));
		}
	}
	return zip_list;
}

sl_cell_t* find_last_sl_list(sl_list_t* l, double value) {
	assert(l);
	sl_cell_t* last_found = NULL;
	if(l->first) {
		if(l->first->value == value)
			last_found = l->first;
		sl_cell_t* current_cell = l->first;
		while(current_cell->next) {
			current_cell = current_cell->next;
			if(current_cell->value == value)
				last_found = current_cell;
		}
		return last_found;
	}
	return last_found;
}

sl_cell_t* reverse_sl_list(sl_list_t* l) {
	assert(l);
	if(!l->first)
		return l;
	sl_cell_t* current_cell = l->first;
	sl_list_t* reversed_list = create_sl_list();
	push_front_sl_list(reversed_list, current_cell);
	while(current_cell->next) {
		current_cell = current_cell->next;
		push_front_sl_list(reversed_list, current_cell);
	}
	return reversed_list;
}

