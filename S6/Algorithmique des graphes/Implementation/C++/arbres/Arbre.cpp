#include "Arbre.h"

template <typename T, unsigned int N>
Arbre<T, N>::Arbre() : valeur(nullptr) {
    for (unsigned int i = 0; i < N; ++i) {
        fils[i] = nullptr;
    }
}

template <typename T, unsigned int N>
Arbre<T, N>::~Arbre() {
    delete[] fils;
}

/* Accesseurs et mutateurs */
template <typename T, unsigned int N>
Arbre* Arbre<T, N>::fils_N(unsigned int n) const {
    assert(n > N);
    return &fils[n];
}

template <typename T, unsigned int N>
void Arbre<T, N>::fils_N(unsigned int n, const Arbre* arbre) {
    assert(n > N);
    fils[n] = *arbre;
}

template <typename T, unsigned int N>
T Arbre<T, N>::valeur() const {
    return val;
}

template <typename T, unsigned int N>
void Arbre<T, N>::valeur(T valeur) {
    this->val = valeur;
}

/* Supprimer */
template <typename T, unsigned int N>
void Arbre<T, N>::supprimer(T element) {
    if(!vide(this))
}

template <typename T, unsigned int N>
void Arbre<T, N>::supprimer(Arbre& arbre, T element) {
    arbre.supprimer(element);
}

/**
 * Fonction booléenne
 */

/* Vide? */
template<typename T, unsigned int N>
bool Arbre<T, N>::vide() const {
    return val == nullptr && &fils[0] == nullptr;
}

template<typename T, unsigned int N>
bool Arbre<T, N>::vide(const Arbre *arbre) const {
    return false;
}

/* Feuille? */
template <typename T, unsigned int N>
bool Arbre<T, N>::feuille() const {
    for (int i = 0; i < N; ++i) {
        if(!vide(fils[i]))
            return false;
    }
    return true;
}

template <typename T, unsigned int N>
bool Arbre<T, N>::feuille(const Arbre& arbre) {
    return arbre.feuille();
}

/* Contient? */
template <typename T, unsigned int N>
bool Arbre<T, N>::contient(T element) const {
    // TODO
}

template <typename T, unsigned int N>
bool Arbre<T, N>::contient(const Arbre& arbre, T element) {
    return arbre.contient(element);
}

/**
 * Fonctions info
 */

/* Profondeur */
template <typename T, unsigned int N>
unsigned int Arbre<T, N>::profondeur(const Arbre* noeud) const {
    // TODO
}

template <typename T, unsigned int N>
unsigned int Arbre<T, N>::profondeur(const Arbre& arbre, const Arbre* noeud) {
    return arbre.profondeur(noeud);
}

/* Hauteur */
template <typename T, unsigned int N>
unsigned int Arbre<T, N>::hauteur() const {
    // TODO
}

template <typename T, unsigned int N>
unsigned int Arbre<T, N>::hauteur(const Arbre& arbre) {
    return arbre.hauteur();
}

/* Taille */
template <typename T, unsigned int N>
unsigned int Arbre<T, N>::taille() const {
    // TODO
}

template <typename T, unsigned int N>
unsigned int Arbre<T, N>::taille(const Arbre& arbre) {
    return arbre.taille();
}

