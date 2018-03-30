#ifndef ARBRE_H
#define ARBRE_H

typedef struct noeud_t* arbre_t;

typedef struct {
	int valeur;
	arbre_t fg, fd;
} noeud_t;

arbre_t * créer_arbre();

void detruire_arbre(arbre_t * arbre);

int vide(arbre_t * arbre);

arbre_t * gauche(arbre_t * arbre);

arbre_t * droite(arbre_t * arbre);

#endif
