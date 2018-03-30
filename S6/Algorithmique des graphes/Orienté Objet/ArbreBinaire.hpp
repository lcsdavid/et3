#pragma once

##include "Arbre.hpp"

template <typename T>
class ArbreBinaire : public Arbre<T, 2> {
protected:
	typename fils[0] fg;
	typename fils[1] fd;

public:
	ArbreBinaire();


	ArbreBinaire* gauche() const;
	ArbreBinaire* droite() const;
};
