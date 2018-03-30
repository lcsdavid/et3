#ifndef ARBRE_HPP
#define ARBRE_HPP

template <typename T, unsigned int N>
class Arbre {
protected:
	T valeur;
	Arbre* fils[N];

public:
	Arbre(); // Constructeur par défaut. (= Arbre vide)
	Arbre(const T& val); // Création Arbre avec racine contenant val.
	Arbre(const Arbre& a); // Constructeur par copie.
	Arbre(const Arbre& ag, const Arbre& ad);

	bool vide() const;
	bool feuille() const;

	Arbre* fils_N(unsigned int N) const;
};

#endif
