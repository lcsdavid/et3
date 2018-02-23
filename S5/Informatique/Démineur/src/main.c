#include <locale.h>

#include "demineur.h"

int main() {
	setlocale(LC_CTYPE,"C-UTF-8");
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
	int pointer_position[2] = {0 , 0};
	display_grid(level, pointer_position, n_size, m_size);
	getch();
    endwin();
    return 0;
}
