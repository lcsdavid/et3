#include "dl_list.h"

dl_list_t* create_dl_list() {
	dl_list_t* that = malloc(sizeof(dl_list_t));
	that->first = NULL;
	that->last = NULL;
	return that;
}

