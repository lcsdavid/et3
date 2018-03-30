#pragma once

#include "ArbreBinaire.hpp"

template <typename T>
class ArbreBinaireRecherche : public ArbreBinaire<T> {
public:

	void ajouter(T x);

	bool rechercher(T x) const;

	void supprimer(T x);

private:
	void sans_max(T& v);

};
