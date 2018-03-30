# Chapitre 4 : Arbres binaires de recherche

## III - Recherche dans un ABR

Utilisation des propriérés de l'ABR  pour reduire le sous-ABR où l'on recherche.

``` java
Fonction Recherche(x : élément, A : Arbre) : Booléen
	Si A = Vide Alors rendre Faux
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
	Si !vide(A) Alors
		Si x <= contenu(racine(A)) Alors Ajouter(x, gauche(A))
		Sinon Ajouter(x, droite(A))
	Sinon accrocher à cette place l'Arbre(x, vide, vide)
```

**Complexité** linéaire en la hauteur de l'arbre.

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
	Si !vide(A) Alors
		Si x < val(A) Alors Supprimer(x, gauche(A)) // on cherche à  gauche
		Sinon
			Si x > val(A) Alors Supprimer(x, droite(A)) // on cherhce à droite
			Sinon
				Si vide(gauche(A)) Alors A <- droite(A)
				Sinon	// on a trouvé
					Si vide(droite(A)) Alors A <- gauche(A)
					Sinon
						Sans_Max(gauche(A), v)	// suppression du max du sous-arbre
						val(A) <- v
```

**Complexité** linéaire en la hauteur de l'arbre.

``` java
Procédure Sans_Max(var A : Arbre, var V : élément)
	// enlève de l'Arbre A supposé non vide sa plus grande feuille, la place associée, et récupère la valeur du maximum dans la variable v
	Si vide(droite(A)) Alors	// plus rien à droite
		V <- val(A)	// on récupère la valeur
		A <- gauche(A) // on enlève la racine et on garde ce qui est à gauche
	Sinon Sans_Max(gauche(A), V) // on descend à droite
```

**Complexité** linéaire en la hauteur de l'arbre.


# Chapitre 6 : Graphes

## III - Parcours en profondeur récursif

**But**: passer une seule fois par tous les sommets en utilisant seulement les arcs du graphe.

**Principe** (récursif):

- partir d'un sommet donné et suivre un chemin le plus loin possible.
- revenir en arrière pour suivre les chemins initialement ignorés.

**NB**: le parcours effectué dépend de l'ordre dans lequel les sommets ont été numérotés !

## IV - Parcours en profondeur itératif

... comme pour les arbres, on utilise unepile pour gérer les remontées le long des branches.

## V - Parcours en largeur

**Principe**: à partir d'un sommet, visiter tous ses successeurs immédiats puis tous les successeurs (non visités) des successeurs de la première liste, etc...

**->** Là aussi, le parcours dépend de l'ordre dans lequel on numérote les sommets.

``` java
Procédure parcourir_en_largeur(G : Graphe)
	// on utilise un tableau M pour marquer les sommets traités.
	Pour s allant de 1 à G.taille Faire
		M[s] <- Faux;
	Pour s allant de 1 à G.taille Faire
		Si(!M[s]) Alors largeur(s, G, M)

Procédure largeur(s : Sommet, G : Graphe, var M : Tableau[sommets] de Booléen)
	M[s] <- Vrai
	Traiter(s)
	New(F) // F, var. locale, file initialisée à vide
	Ajouter s à F
	Tant que !vide(F) Faire
	 	w <- tête(F) // w, var. locale, sommet
		décapiter(F)
		P <- G.T[w] // P, var. locale, liste d'adjacence
		Tant que !vide(P) Faire
			v <- P.numéro // v, var. locale, contient le numéro du sommet adjacent à w courant
			Si !M[v] Alors
				M[v] <- Vrai
				Traiter(v)
				Ajouter v à F
```

**Remarque** : le parcours obtenu ne dépend pas que du graphe, mais aussi de l'ordre dans lequel les sommets ont été numérotés. Exemple: code de GRAY.


# Chapitre 7 - Arbre de recouvrement minimal d'un graphe

## I - Arbre et graphes connexes

#### Notion de connexité (graphes orientés/non orientés)

**Connexité**: capacité de visiter les noeuds du graphe en suivant des chemins sur les arcs/arêtes.

__Graphe fortement connexe (graphe orienté)__:  
pour toute paire de sommets (u,v) il existe un allant de v à u ET un chemin allant de v à u.

__Graphe connexe (graphe non orienté)__:  
pour toute paire de sommets (u,v), il existe une chaîne notée u--*--v d'extrémités u et v (et vice-versa).

__Composante fortement connexe d'un graphe orienté__:  
sous-graphe fortement connexe maximal (pour l'inclusion).

__Composante connexe d'un graphe non orienté__:  
sous-graphe connexe maximal (pour l'inclusion).

__Arbre de reocuvrement minimal__:  
revient à trouver un chemin reliant les sommets en choissant les arêtes de coût faible.

__Composante connexe__:  
on peut circueler partout à l'intérieur d'un graphe connexe et partout dans les composantes connexes d'un graphe non connexe MAIS on ne peut pas passer d'une composante connexe à l'autre en utilisant que les arêtes du graphe.

**Arbre de recouvrement d'un graphe connexe**  
G=<S,A,C> graphe non orienté valué à N sommets.

- P1: G est un graphe connexe sans cycle
- P2: G est un graphe connexe ET il n'est plus connexe si l'on supprime une arête
- P3: G est un graphe connexe minimal
- P4: G est sans cycle et si l'on une arête, on crée un cycle
- P5: G est sans cycle et si l'on ajoute une arête, on crée un cycle
- P6: G est sans cycle avec N - 1 arêtes
- P7: G est un graphe tel qu'il existe une chaîne unique reliant deux sommets quelconques entre eux

On a équivalence entre toutes les propriérés.

__Proriété de reocuvrement minimal (RM)__:  
Un sous-ensemble T d'arêtes verifie la propriété RM s'il est tel que tous les sommets de S sont connectés par des arêtes de T et que la somme de valuations des arêtes de T est minimale parmi les sous-ensemble d'arêtes préservant la connexité.  
T: [Pourtout u,v € S, ilesxite chaîne u--*--v dans T]  
et somme (? arêtes de T) minimale.  
Et on peut aussi écrire:  
pourtout T' vérifiant la propriété de connexité som(coûts arêtes de T) <= som(coûts arêtes T')

## II - Définition du problème

Soit G=(S,A,C), graphe simple, non orienté, valué, connexe.  
Chercher un arbre de reocuvrement minimal revient à restraiendre A à un sous-ensemble T d'arêtes vérifiant la condition de **RM**.

__Théorème d'éxistance d'un arbre de recouvrement minimal__  
Il existe au moins un sous-ensemble d'arêtes T vérfiant la propriété de **RM** ; le graphe partiel (S,T) est un arbre que l'on appellera **Arbre de Recouvrement Minimal** de G : **ARM**(G)

**NB**: Il existe au moins un sous-ensemble T d'arêtes respectant la propriété de minimalité MAIS il peut ne pas être unique.  
Le partiel (S,T) est forcément un arbre, de par les conditions de minimalité et de connexité.  
Un graphe valué non orienté connexe peut avoir plsusierus arbres de recouvrement minimal (tous de même poids) MAIS s'il existe une seule arête de poids minimal, elle appartient à tous les arbres de recouvrement minimal.
- si le graphe est tel que les coûts des arêtes sont distincts 2 à 2, alors l'arbre de recourvrement minimal est unique.

__- bidule manquant -__

__Aparté: Algorithme glouton/gourmand (vorace)__  
**Greedy algorthm...**  
Algorithme faisant, à chaque étape, me cjoix d'un optimum local (au lieu de tester tous les ...)

__Idée d'algorithme: Kruskal__  
- chaque sommet est une composante: partition de S
- examiner les arêtes de poids minimal une à une pour rassembler les composantes
- condition d'arrêt ?
- ordre d'examen des arêtes: celui de leur valuation en ordre croissant

**Condition d'arrêt**: quand le nombre d'arêtes dans T est égal au nombre de sommets - 1.  
A tout moment, le graphe de sommets s et d'arêtes T a plusieurs composantes connexes recouvertes chacune par un arbre minimal. (felix)


__Algorithùme de Kruskal, version "macro"__  
...
