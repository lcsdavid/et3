#include "demineur.h"

int main() {
    initscr();
	//raw();
	//cbreak();
	keypad(stdscr, TRUE);
	noecho();
    curs_set(0);
    size_t n_size, m_size;
    unsigned int mine_count;
    menu(&n_size, &m_size, &mine_count);
	clear();
	refresh();
	int*** level = create_level(n_size, m_size, mine_count);
	display_grid(level, n_size, m_size);
	getch();
    endwin();
    return 0;
}
