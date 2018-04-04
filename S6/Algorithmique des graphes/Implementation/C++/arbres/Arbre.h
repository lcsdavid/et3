#pragma once

#include <cassert>

template <typename T, unsigned int N>
class Arbre {
protected:
	T val;
	Arbre fils[N];

public:
	Arbre(); // Constructeur par défaut. (= Arbre vide)
	~Arbre();

	/* Accesseurs et mutateurs */
	Arbre* fils_N(unsigned int N) const;
	void fils_N(unsigned int N, const Arbre* arbre);

	T valeur() const;
	void valeur(T valeur);

	/* Fonction modficatrice */
	void supprimer(T element);
	static void supprimer(Arbre& arbre, T element);

	/* Fonction booléenne */
	bool vide() const;
	static bool vide(const Arbre& arbre);

	bool feuille() const;
	static bool feuille(const Arbre& arbre);

	bool contient(T element) const;
	static bool contient(const Arbre& arbre, T element);

	/* Fonctions info */
	unsigned int profondeur(const Arbre* noeud) const;
	static unsigned int profondeur(const Arbre& arbre, const Arbre* noeud);

	unsigned int hauteur() const;
	static unsigned int hauteur(const Arbre& arbre);

	unsigned int taille() const;
	static unsigned int taille(const Arbre& arbre);


};

#endif
