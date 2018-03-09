# Chapitre 4 : Arbres binaires de recherche

## III - Recherche dans un ABR

### III.Recherche d'un élément dans un ABR
Utilisation des propriérés de l'ABR  pour reduire le sous-ABR où l'on recherche.

``` java
Fonction Recherche(x:élément, A: Arbre) : Booléen
	Si A = Vide alors rendre Faux
	Sinon Si x = contenu(racine(A)) Alors rendre Vrai
			Sinon Si x < contenu(racine(A))
				Alors rendre Recherche(x, gauche(A))
				Sinon rendre Recherche(x, droite(A))
```

**Complexité** au moins logarithmique.

## IV - Ajouter un élément et une place en une feuille

**Impératif**: conserver la structure d'ABR.

**Principe**: déterminer la bonne place pour l'élément, et l'y mettre.

**Modus operandi**: parcourir l'arbre récursivement jusqu'à trouver une feuille, ajouter en cette feuille.

``` java
Procédure Ajouter(x : élément, var A : ABR)
	Si A != vide Alors
		Si x <= contenu(racine(A)) Alors Ajouter(x, gauche(A))
		Sinon Ajouter(x, droite(A))
	Sinon accrocher à cette place l'Arbre(x, vide, vide)
```

**Complexité**: linéaire en la hauteur de l'arbre.

## V - Construire un ABR par adjonction

**But**: construction d'un arbre "à la volée" par adjonction de feuille... on utilise ce qui précède.

``` java
Procédure Construire(var A: ABR)
	// construit un ABR en prenant des entrées clavier par adjonction successives de feuilles
	A = null
	Lire_Valeur(k)	// entrée clavier ou fichier
	Répéter
		Ajouter(k, A)
		Lire_Valeur(k)
	Jusqu k = default
```

**Recursivement**

``` java
Fonction faire_ABR(L : liste) : ABR
	rendre faire(L, null)
```

``` java
Fonction faire(L : liste, var A : ABR) : ABR
	Si L = null Alors rendre A
	Sinon
		B <- faire(fin(L), A)
		Ajouter(L.val, B)
		rendre(B)
```

**Itératif**

``` java
Procédure faire(var A : Arbre, L : liste)
	// variables locales: P : liste
	New(A)
	P <- L
	Tant que P != null Faire
		Ajouter(P.val, A)
		P <- P.suiv
```

## VI - Supprimer un élément et une place

**But**: supprimer un élément donné en en récupérant la place ET en conservant une structure d'ABR.

**Procédé**: Recherche l'élement, le supprimer, utiliser la place pour un autre élément (judicieusement choisi) dont on supprimera la place.

**Concrètement**: on retire la max et on remet sa valeur à l'emplacement de l'élement à supprimer.

``` java
Procédure Supprimer(x : élément, var A : Arbre)
	// supprime l'élément x de l'Arbre A

Procédure Sans_Max(var A : Arbre, var v : élément)
	// enlève de l'Arbre A supposé non vide sa plus grande feuille, la place associée, et récupère la valeur du maximum dans la variable v

```

**Complexité**: linéaire en la hauteur de l'arbre.
