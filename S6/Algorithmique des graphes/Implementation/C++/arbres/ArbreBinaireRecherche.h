#pragma once

#include "ArbreBinaire.h"

template <typename T>
class ArbreBinaireRecherche : public ArbreBinaire<T> {
public:
	ArbreBinaireRecherche();
	ArbreBinaireRecherche(T valeur);
	~ArbreBinaireRecherche();

	void ajouter(T x);

	bool rechercher(T x) const;

	void supprimer(T x);

private:
	void sans_max(T& v);

};
