#include "arbre.h"

arbre_binaire_t creer_arbre_binaire(int valeur, arbre_binaire_t fg, arbre_binaire_t fd) {
    arbre_binaire_t that = malloc(sizeof(struct noeud_binaire));
    if(that == NULL) {
        perror("malloc()");
    } else {
        that->val = valeur;
        that->fg = fg;
        that->fd = fd;
    }
    return that;
}

void detruire_arbre(arbre_binaire_t a) {
    if (!vide(a->fg))
        detruire_arbre(a->fg);
    if (!vide(a->fd))
        detruire_arbre(a->fd);
    free(a);
}

int vide(arbre_binaire_t a) {
    return a == NULL;
}


int feuille(arbre_binaire_t a) {
    return vide(a) || (vide(a->fg) && vide(a->fd));
}