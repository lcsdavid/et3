#ifndef ARBRE_H
#define ARBRE_H

typedef struct noeud_t* arbre_t;

typedef struct {
	int val;
	arbre_t g, d;
} noeud_t;

arbre_t * créer_arbre();

void detruire_arbre(arbre_t * arbre);

int vide(arbre_t * arbre);

arbre_t * fils_gauche(arbre_t * arbre);

arbre_t * fils_droit(arbre_t * arbre);

#endif