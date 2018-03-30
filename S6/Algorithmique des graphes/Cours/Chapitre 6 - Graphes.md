# Chapitre 6 : Graphes

## 0 - Graphes: définitions

- **Graphe non orienté**: couple <S,A> où
 - S est un ensemble de sommets
 - A est un ensemble d’**Arêtes**
 - **Arête**: couple de sommets a = {u,v}


- **Graphe orienté**: couple <S,A> où
 - S est un ensemble fini de sommets
 - A est un ensemble d’Arcs
 - Arc (ou "arêtes orientées"): a = (u,v). a connecte u (origine) à v (extrémité terminale).


- **Graphe valué (non) orienté**: triplet <S,A,C>
 - <S,A> est un graphe (non) orienté
 - C est appelé le coût (valuation, poids):
   - fonction de l'ensemble A dans R
   - par défaut, c(a) = 1 si a existe et 0 sinon


- **boucle**: arête/arc connectant un sommet à lui-même.
- **multigraphe (non) orienté**: graphe où plusieurs arcs ou arêtes distincts peuvent joindre deus sommets.
- **multi-arc/multi-arête**: triplets <a,u,v> <b,u,v> tels que a != b.


- **sous-graphe**: graphe G' engendré par
 - S' (sous-ensemble pris parmi les sommets de G).
 - A' (sous-ensemble des arêtes les reliant, pris parmi les arêtes de G).


- **arcs/arêtes adjacents**: ont une extrémité commune.
- **sommets adjacents** (graphe non orienté): sont reliés par une arête.


- **arc incident** (graphe orienté): a = u -> est
 - incident à u vers l'extérieur.
 - incident à v vers l'intérieur.


- **chemin/chaîne de longueur *l***: suite de *l*+1 sommets reliés par des arêtes/arcs (voir **tableau** (manquant)).
- **chemin/chaîne élémentaire**: contient une seule fois chaque sommet.


- **circuit/cycle**: chemin/chaîne dont
 - les arcs/arêtes sont distincts 2 à 2.
 - les deux extrémités sont égales.


- **graphe orienté fortement connexe**: pour toute paire de sommets (u,v), il existe un chemin allant de u à v et un chemin allant de v à u.
- **graphe orienté fortement connexe**: pour toute paire de sommets (u,v), il existe un chemin allant de u à v et un chemin allant de v à u.
- **composante fortement d'un graphe orienté**: sous-graphe fortement connexe maximal.
- **graphe non orienté connexe**: pour toute paire de sommets (u,v), il existe une chaîne d'extrémités u et v.
- **composante connexe d'un graphe non orienté**: sous-graphe connexe maximal.

## 1 - Représentation des graphes par des matrices d'adjacences

__Matrice d'adjacence d'un graphe:__
- Les sommets constituent les indices du tableau
- Un booléen indique s'il y a un arc entre deux sommets
- Dans le cas d'un graphe pondéré la matrice contient le poids des arcs

# ALGO manquant

**->** Représentation adaptée pour les graphes très pleins  
**->** Certaines fonctions de manipulation des graphes sont complexes à implémenter sous cette forme

## 2 - Représentation des graphes par des listes d'adjacences

__Liste d'adjacence d'un graphe:__
- Le graphe est donné par ses sommets et ses arcs.
- Les sommets sont les indices d'un tableau.
- À chaque sommet est associée la liste de ses successeurs immédiats (listes d'adjacence).
- Si la taille du graphe évolue beaucoup, on utilise une liste de sommets et non un tableau de sommets.

# ALGO manquant

**->** Représentation adaptée pour les graphes où le nombre d'arcs est relativement faible  
**->** Opérations globales facilitées

## 3 - Parcours en profondeur récursif

**But**: passer une seule fois par tous les sommets en utilisant seulement les arcs du graphe.

**Principe** (récursif):

- partir d'un sommet donné et suivre un chemin le plus loin possible.
- revenir en arrière pour suivre les chemins initialement ignorés.

**NB**: le parcours effectué dépend de l'ordre dans lequel les sommets ont été numérotés !

## 4 - Parcours en profondeur itératif

... comme pour les arbres, on utilise unepile pour gérer les remontées le long des branches.

## 5 - Parcours en largeur

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
