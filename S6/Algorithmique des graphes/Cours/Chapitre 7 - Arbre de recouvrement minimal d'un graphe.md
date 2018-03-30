# Chapitre 7 - Arbre de recouvrement minimal d'un graphe

## 1 - Arbre et graphes connexes

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

Soit G=<S,A,C>, graphe simple, non orienté, valué, connexe.  
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
