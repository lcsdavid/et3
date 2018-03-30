#pragma once

template <typename T, unsigned int N>
class Arbre {
protected:
	T valeur;
	Arbre* fils[N];

public:
	Arbre(); // Constructeur par défaut. (= Arbre vide)

	/* Accesseurs et mutateurs */
	Arbre* fils_N(unsigned int N) const;
	void fils_N(unsigned int N, const Arbre* arbre);

	T valeur() const;
	void valeur(T valeur);

	/* Fonction modficatrice */
	void ajouter_gauche(const Arbre* sous_arbre);
	static void ajouter_gauche(Arbre& arbre, const Arbre* sous_arbre);

	void ajouter_droite(const Arbre* sous_arbre);
	static void ajouter_droite(Arbre& arbre, const Arbre* sous_arbre);

	void supprimer(T élément);
	static void supprimer(Arbre& arbre, T élément);

	/* Fonction booléenne */
	static bool vide(const Arbre* arbre) const;

	bool feuille() const;
	static bool feuille(const Arbre& arbre);

	bool contient(T élément) const;
	static bool contient(const Arbre& arbre, T élément);

	/* Fonctions info */
	unsigned int profondeur(const Arbre* noeud) const;
	static unsigned int profondeur(const Arbre& arbre, const Arbre* noeud);

	unsigned int hauteur() const;
	static unsigned int hauteur(const Arbre& arbre);

	unsigned int taille() const;
	static unsigned int taille(const Arbre& arbre);


};

#endif
