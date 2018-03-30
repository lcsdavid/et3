#include "Arbre.hpp"

template <typename T, unsigned int N>
Arbre<T,N>::Arbre() : valeur(static_cast<T>(0)) {
    for (unsigned int i = 0; i < N; ++i) {
        fils[i] = nullptr;
    }
}

template <typename T, unsigned int N>
Arbre<T,N>::~Arbre() {
    delete[] fils;
}

/* Accesseurs et mutateurs */
template <typename T, unsigned int N>
Arbre* Arbre<T,N>::fils_N(unsigned int n) const {
    assert(n > N);
    return fils[n];
}

template <typename T, unsigned int N>
void Arbre<T,N>::fils_N(unsigned int n, const Arbre* arbre) {
    assert(n > N);
    fils[n] = arbre;
}

template <typename T, unsigned int N>
T Arbre<T,N>::valeur() const {
    return valeur;
}

template <typename T, unsigned int N>
void Arbre<T,N>::valeur(T valeur) {
    this.valeur = valeur;
}

/* Fonction modficatrice */
template <typename T, unsigned int N>
void Arbre<T,N>::ajouter_gauche(const Arbre* sous_arbre);
template <typename T, unsigned int N>
void Arbre<T,N>::ajouter_gauche(Arbre& arbre, const Arbre* sous_arbre);

template <typename T, unsigned int N>
void Arbre<T,N>::ajouter_droite(const Arbre* sous_arbre);
template <typename T, unsigned int N>
void Arbre<T,N>::ajouter_droite(Arbre& arbre, const Arbre* sous_arbre);

/* Supprimer */
template <typename T, unsigned int N>
void Arbre<T,N>::supprimer(T élément) {
    // TODO
}

template <typename T, unsigned int N>
void Arbre<T,N>::supprimer(Arbre& arbre, T élément) {
    arbre.supprimer(T);
}

/**
 * Fonction booléenne
 */

/* Vide? */
template <typename T, unsigned int N>
bool Arbre<T,N>::vide(const Arbre* arbre) {
    return arbre == nullptr;
}

/* Feuille? */
template <typename T, unsigned int N>
bool Arbre<T,N>::feuille() const {
    for (int i = 0; i < N; ++i) {
        if(!vide(fils[i]))
            return false;
    }
    return true;
}

template <typename T, unsigned int N>
bool Arbre<T,N>::feuille(const Arbre& arbre) {
    return feuille(arbre);
}

/* Contient? */
template <typename T, unsigned int N>
bool Arbre<T,N>::contient(T élément) const {
    // TODO
}

template <typename T, unsigned int N>
bool Arbre<T,N>::contient(const Arbre& arbre, T élément) {
    return arbre.contient(T);
}

/**
 * Fonctions info
 */

/* Profondeur */
template <typename T, unsigned int N>
unsigned int Arbre<T,N>::profondeur(const Arbre* noeud) const {
    // TODO
}

template <typename T, unsigned int N>
unsigned int Arbre<T,N>::profondeur(const Arbre& arbre, const Arbre* noeud) {
    return arbre.profondeur(noeud);
}

/* Hauteur */
template <typename T, unsigned int N>
unsigned int Arbre<T,N>::hauteur() const {
    // TODO
}

template <typename T, unsigned int N>
unsigned int Arbre<T,N>::hauteur(const Arbre& arbre) {
    return arbre.hauteur();
}

/* Taille */
template <typename T, unsigned int N>
unsigned int Arbre<T,N>::taille() const {
    // TODO
}

template <typename T, unsigned int N>
unsigned int Arbre<T,N>::taille(const Arbre& arbre) {
    return arbre.taille();
}