#pragma once

#include "Arbre.h"

template <typename T>
class ArbreBinaire : public Arbre<T, 2> {

public:
	ArbreBinaire();
	ArbreBinaire(T valeur, ArbreBinaire* fg, ArbreBinaire* fd);
	~ArbreBinaire();

	ArbreBinaire* gauche() const;
	ArbreBinaire* droite() const;
};
