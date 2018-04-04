#ifndef ARBRE_H
#define ARBRE_H

#include <stdlib.h>

typedef struct noeud_binaire* arbre_binaire_t;

struct noeud_binaire {
	int val;
	arbre_binaire_t fg, fd;
};

arbre_binaire_t creer_arbre_binaire(int valeur, arbre_binaire_t fg, arbre_binaire_t fd);

void detruire_arbre(arbre_binaire_t a);

int vide(arbre_binaire_t a);

int feuille(arbre_binaire_t a);

#endif
