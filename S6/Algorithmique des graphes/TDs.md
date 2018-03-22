
# TD 2 - ABR

## Exercice 1: Recherche d'un noeud dans un ABR. 

``` cpp
ABR rechercher(élément n, ABR A) {
	if (vide(A))
	return nullptr
	if (A.valeur > n)
	return rechercher(n, A.fg)
	else if (A.valeur < n)
	return rechercher(n, A.fd)
	else
	return A
```
