#include "fonctions.h"

char increment_char(char c, int increment) {
	return (c + increment - 'a') % 26 + 'a';
}

void increment_str(char* str, int increment) {
	for(int i = 0; i < strlen(str); ++i)
		str[i] = increment_char(str[i], increment);
}

int isLowerCase(char* str) {
	for(int i = 0; i < strlen(str); i++) {
		if(str[i] == ' ') {
			printf("Pas d'espace autorisée...");
			return 0;
		} else if (str[i] < 'a' || str[i] > 'z') {
			printf("Seul les minuscules sont autorisées..\n");
			return 0;
		}
	}
	return 1;
}

void encode() {
	char word[256];
	int increment = 0;
	do {
		printf("Entrez une chaine de caractère (minuscules uniquement)... ou appuyez sur q.\n");
		scanf("%s", word);
		if(word[0] == 'q')
			return;
	} while(!isLowerCase(word));
	printf("Donnez un increment...\n");
	scanf("%d", &increment);
	increment_str(word, increment);
	printf("Message codé: %s\n", word);
}

void riceSissa(int n) {
	long result = 0;
	long power = 1;
	for(int i = 0; i < n * n; i++) {
		result += power;
		power *= 2;
 	}
	printf("%ld grains de riz!\n", result);
}

int factorial(int n) {
	int result = 1;
	for(int i = 2; i < n + 1 /* ou i <= n c'est pareil */; i++)
		result *= i;
	return result;
}

int recursive_factorial(int n) {
	if(n == 0 || n == 1) // cas d'arrêt
		return 1;
	return n * recursive_factorial(n - 1); // présence de la récursivité
}
