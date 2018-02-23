#include "fonctions.h"

int main() {
	// 3.1
	printf("%c + %d = %c\n", 'a', 10, increment_char('a', 10));

	// 3.2
	char phrase[64] = "jaimeleschats";
	printf("%s", phrase);
	increment_str(phrase, 1);
	printf(" devient la phrase (avec l'increment %d): %s.\n", 1, phrase);

	// 3.3
	encode();

	// 3.4
	// Pour éviter les redondances.

	// 3.5
	// cf. int isLowerCase(char*);

	// 4.1
	riceSissa(5);

	// 4.2
	// Le nombre dépasse la valeur max du int, long, etc...

	// 4.3 4.4 4.5 osef

	// 5.1
	printf("%d! vaut %d\n", 8, factorial(8));

	// 5.2
	printf("%d! vaut %d\n", 5, recursive_factorial(5));

	// 5.3
	// Une fonction recursive consomme + de mémoire, mais permet de résoudre que
	// l'on ne peut pas résoudre pas itération (parcours d'arbre de recherche par exemple.)

	// 6 osef go voir le TP suivant
	return 0;
}
