#ifndef DEMINEUR_H
#define DEMINEUR_H

#include <ncurses.h>

#include "matrix.h"
#include "array.h"

void menu(size_t *n_size, size_t *m_size, unsigned int *mine_count);

int ***create_level(size_t n_size, size_t m_size, unsigned int mine_count);

void display_grid(int ***level, size_t n_size, size_t m_size);

void loading(unsigned int percent);

#endif
