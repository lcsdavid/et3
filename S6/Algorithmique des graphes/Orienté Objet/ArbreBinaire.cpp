#include "ArbreBinaire.hpp"

template <typename T>
ArbreBinaire<T>::ArbreBinaire() : valeur(static_cast<T>(0)) {
    fils[0] = nullptr;
    fils[1] = nullptr;
}

template <typename T>
ArbreBinaire<T>::ArbreBinaire(T valeur, ArbreBinaire* fg, ArbreBinaire* fd) : valeur(valeur) {
    fils[0] = fg;
    fils[1] = fd;
}

template <typename T>
ArbreBinaire<T>::~ArbreBinaire() : ~Arbre() {}

template <typename T>
ArbreBinaire* ArbreBinaire<T>::gauche() const {
    return fils[0];
}

template <typename T>
ArbreBinaire* ArbreBinaire<T>::droite() const {
    return fils[1];
}