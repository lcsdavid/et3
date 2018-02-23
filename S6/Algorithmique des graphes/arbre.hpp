#ifndef ARBRE_HPP
#define ARBRE_HPP

template <typename T>
class Arbre {
private:
	T val;
	Arbre* g, d;
	
public:
	Arbre(); // Constructeur par défaut. (= Arbre vide)
	Arbre(const T& val); // Création Arbre avec racine contenant val.
	Arbre(const Arbre& a); // Constructeur par copie.
	Arbre(const Arbre& ag, const Arbre& ad);
	
	bool vide() const;
	
	Arbre* fils_gauche() const;
	Arbre* fils_droit() const;
	
	
}

#endif