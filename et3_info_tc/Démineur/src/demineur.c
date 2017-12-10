#include "demineur.h"

void menu(size_t *n_size, size_t *m_size, unsigned int *mine_count) {
    int level_selected = 0;
    int keyboard_entry = 0;
    int selection = 0;
    int n = 5;
    int m = 5;
    int mine = 10;
    while (!level_selected) {
        attron(A_BOLD);
        mvprintw(1, (COLS - 23) / 2, "Bienvenue dans Démineur");
        attroff(A_BOLD);
        mvprintw(3, 4, "Taille de la carte: ");
        if (selection == 0) {
            attron(A_BOLD);
            printw("%d", n);
            attroff(A_BOLD);
            printw("x%d ", m);
            move(4, 4);
            printw("Nombre de mines: %d", mine);
        } else if (selection == 1) {
            printw("%dx", n);
            attron(A_BOLD);
            printw("%d ", m);
            attroff(A_BOLD);
            move(4, 4);
            printw("Nombre de mines: %d", mine);
        } else {
            printw("%dx%d\n", n, m);
            move(4, 4);
            printw("Nombre de mines: ");
            attron(A_BOLD);
            printw("%d", mine);
            attroff(A_BOLD);
        }
        keyboard_entry = getch();
        switch (keyboard_entry) {
			case KEY_UP: // KEY ARROW UP 65
                if (selection == 0) {
                    n = (n - 4) % 36 + 5;
                    mine = n + m;
                } else if (selection == 1) {
                    m = (m - 4) % 36 + 5;
                    mine = n + m;
                } else {
                    mine = (mine + 1 - n - m) % (n * m - 2 * n - 2 * m + 1) + n + m;
                }
                break;
			case KEY_DOWN: // KEY ARROW DOWN 66
				if (selection == 0) {
					if (n == 5)
						n = 40;
					else
						n = (n - 6) % 36 + 5;
						mine = n + m;
				} else if (selection == 1) {
					if (m == 5)
						m = 40;
					else
						m = (m - 6) % 36 + 5;
					mine = n + m;
				} else {
					if (mine == n + m)
						mine = n * m - n - m;
					else
						mine = (mine - 1 - n - m) % (n * m - 2 * n - 2 * m + 1) + n + m;
				}
				break;
            case KEY_RIGHT: // KEY ARROW RIGHT 67
                selection = (selection + 1) % 3;
                break;
            case KEY_LEFT: // KEY ARROW LEFT 68
                if (selection == 0)
                    selection = 2;
                else
                    selection = (selection - 1) % 3;
                break;
            case 10: // KEY ENTER 10
                level_selected = 1;
                break;
            case KEY_RESIZE:
                clear();
                break;
            default:
                break;
        }
        refresh();
    }
    *n_size = (size_t) n;
    *m_size = (size_t) m;
    *mine_count = (unsigned int) mine;
}


int ***create_level(size_t n_size, size_t m_size, unsigned int mine_count) {
    int **mines = loto_2(0, n_size, 0, m_size, mine_count);
    int ***level = malloc(sizeof(int **) * n_size);
    for (size_t i = 0; i < n_size; i++) {
        level[i] = malloc(sizeof(int *) * m_size);
        for (size_t j = 0; j < m_size; j++) {
            level[i][j] = malloc(sizeof(int) * 2);
            level[i][j][0] = 0;
            level[i][j][1] = 0;
        }
    }
    for (size_t k = 0; k < mine_count; k++) {
        level[mines[k][0]][mines[k][1]][0] = -1;
    } /*
    for (size_t k = 0; k < mine_count; k++) {
        int i = mines[k][0];
        int j = mines[k][1];
        // J-1
        if (level[i - 1][j - 1][0] != -1)
            level[i - 1][j - 1][0] += 1;
        if (level[i][j - 1][0] != -1)
            level[i][j - 1][0] += 1;
        if (level[i + 1][j - 1][0] != -1)
            level[i + 1][j - 1][0] += 1;
        // J
        if (level[i - 1][j][0] != -1)
            level[i - 1][j][0] += 1;
        if (level[i + 1][j][0] != -1)
            level[i + 1][j][0] += 1;
        // J+1
        if (level[i - 1][j + 1][0] != -1)
            level[i - 1][j + 1][0] += 1;
        if (level[i][j + 1][0] != -1)
            level[i][j + 1][0] += 1;
        if (level[i + 1][j + 1][0] != -1)
            level[i + 1][j + 1][0] += 1;
    } */
	for (size_t k = 0; k < mine_count; k++) {
        free(mines[k]);
    }
	free(mines);
	return level;
}

void display_grid(int ***level, size_t n_size, size_t m_size) {
    for (size_t i = 0; i < n_size; i++) {
		move(2 + 2 * i, 4);
        for (size_t k = 0; k < m_size * 2 + 1; k++) {
            if (k % 2 == 0)
                printw("+");
           	else
                printw("-");
		}
    	move(3 + 2 * i, 4);
    	for (size_t j = 0; j < m_size; j++) {
        	printw("|");
        	if (level[i][j][1] == 0)
            	printw(" ");
        	else if (level[i][j][1] == 1) {
            	if (level[i][j][0] == 0)
                	printf(" ");
            	else
                	printw("%d", level[i][j][0]);
        	}
    	}
		printw("|");
		move(4 + i * 2, 4);
		for (size_t k = 0; k < m_size * 2 + 1; k++) {
            if (k % 2 == 0)
                printw("+");
           	else
                printw("-");
		}
	}
   	//পᐅ
	refresh();
}
