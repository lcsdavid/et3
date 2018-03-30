
## TD 2 - ABR

### Exercice 1: Recherche d'un noeud dans un ABR.

``` c++
Arbre rechercher(Element n, ABR A) {
	if (vide(A))
		return NULL;
	if (A.valeur > n)
		return rechercher(n, A.fg);
	else if (A.valeur < n)
		return rechercher(n, A.fd);
	else
		return A;
}
```

### Exercice 2: Insertion d'un noeud (feuille) dans un ABR.

``` c++
void inserer(Element n, Arbre& A) {
	if (vide(A))
		A = creer_arbre(n, NULL, NULL);
	else if (A.valeur > n)
		inserer(n, A.fg);
	else if (A.valeur < n)
		inserer(n, A.fd);
	else // égale
		return; // insère pas de doublon
}
```

### Exercice 3: Suppression d'un noeud k.

``` c++
void supprimer(Element k, Arbre& A) {
	if(!vide(A))
		if(k < A.valeur)
			supprimer(k, A.fg);
		else if(k > A.valeur)
			supprimer(k, A.fd);
		else if(vide(A.fg))
			A = A.fd;
		else if(vide(A.fd))
			A = A.fg;
		else {
			Element v;
			sans_max(fg.A, v)
			A.valeur = v;
		}
}

void sans_max(Arbre& A, Element& v) {
	if(vide(A.fd)) {
		v = A.valeur;
		A = A.fd;
	} else sans_max(A.fg, v);
}
```

### Exercice 4: Soit un ABR donner ci-dessous l'algo qui permet de retourner sa rotation.

``` c++
void rotation_gauche(Arbre& A) {
	Arbre B = A;
	A = A.fd;
	B.fd = A.fg;
	A.fg = B;
}

void rotation_droite(Arbre& A) {
	Arbre B = A;
	A = A.fg;
	B.fg = A.fd;
	A.fd = B;
}
```

### Exercice 5: Soit A un ABR équilibré et un entier n. Utiliser les fonctions de rotation afin que A soit équilibré après insertion.

``` c++
void inserer_equilibre(Arbre& A) {
	if (vide(A))
		A = creer_arbre(n, NULL, NULL);
	else if (A.valeur > n);
		inserer_equilibre(n, A.fg);
	else if (A.valeur < n);
		inserer_equilibre(n, A.fd);
	if (!estEquilibre(A)) {
		if(hauteur(A.fg) < hauteur(A.fd))
			rotation_gauche(A);
		else
			rotation_droite(A);
		return;
	}
}
```
