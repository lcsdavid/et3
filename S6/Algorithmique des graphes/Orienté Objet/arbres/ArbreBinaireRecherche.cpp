#include "ArbreBinaireRecherche.hpp"

template <typename T>
ArbreBinaireRecherche<T>::ArbreBinaireRecherche() : ArbreBinaire() {}

template <typename T>
ArbreBinaireRecherche<T>::ArbreBinaireRecherche(T valeur) : ArbreBinaire(T, nullptr, nullptr) {}

template <typename T>
ArbreBinaireRecherche<T>::~ArbreBinaireRecherche() : ~ArbreBinaire() {}