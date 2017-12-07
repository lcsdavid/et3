#include <stdio.h>
#include <stdlib.h>

#include "tableau.h"
#include "rand.h"

int main(int argc, char **argv) {

	/* On affiche combien d'arguments on a mis au lancement du programme */
	printf("Nombre d'arguments: %d\n", argc);

	/* Si argc (nb d'arguments) vaut 1 alors il n'y a pas d'agument. On quitte.
	 	 (L'appelle du programme vaut déjà un argument.)*/
	if(argc == 1) {
		printf("No arguments. Exiting...");
		return 0;
	}

	/* On crée une variable de taille qui compte tous les arguments "utilisable"
		 sachant que le 1er argument est le programme lui même et le deuxième nous
		 sert a préciser qu'elle exercice on veut faire. Donc taille = nb_arguments - 2. */
	size_t size = argc - 2;

	// Ne rien faire argv[1] -> 1.

	// 1.1.i)
	if(atoi(argv[1]) == 2) {
		int array[size];
		/* & -> donne l'adresse donc &argv[2] donne l'adresse du deuxième élement du tableau. */
		string_to_array_int(array, &argv[2], size);
		display_array_int(array, size);
	}

	// 1.1.ii)
	if(atoi(argv[1]) == 3) {
		float array[size];
		string_to_array_float(array, &argv[2], size);
		display_array_float(array, size);
	}

	// 1.2
	if(atoi(argv[1]) == 4) {
		int array[5] = {0 , 10, 20, 45, 50};
		reset_array_int(array, atoi(argv[2]), 5);
		display_array_int(array,size);
	}

	// 1.3
	if(atoi(argv[1]) == 5) {
		int array[5] = {0 , 10, 20, 45, 50};
		if(search_in_array_int(array, atoi(argv[2]), 5))
			printf("%s existe dans ", argv[2]);
		else
			printf("%s n'as pas été trouvé dans ", argv[2]);
		display_array_int(array, 5);
	}

	// 1.4
	if(atoi(argv[1]) == 6) {
		int array[10] = {0, 10, 10, 10, 20, 20, 45, 50, 50, 50};
		printf("Il y a %d fois le %d dans ", occurence_in_array_int(array, atoi(argv[2]), 10),  atoi(argv[2]));
		display_array_int(array, 5);
	}

	// 1.5
	if(atoi(argv[1]) == 7) {
		// On verifie qu'on est bien le bon nombre d'argument (falcutatif).
		if(argc != 5) {
			printf("Wrong number of arguments. Exiting...");
			return -1;
		}
		// On stock la taille du tableau depuis argv[4].
		size_t size = atoi(argv[4]);
		int array[size];
		// On crée le tableau d'entier aléatoire, argv[2] -> valeur min, argv[3] -> valeur max.
		rand_array_int(array, atoi(argv[2]), atoi(argv[3]), size);
		display_array_int(array, size);
	}

	// 1.6
	if(atoi(argv[1]) == 8) {
		// On verifie qu'on est bien le bon nombre d'argument (falcutatif).
		if(argc != 6) {
			printf("Wrong number of arguments. Exiting...");
			return -1;
		}
		// On choisit la taille aléatoirement argv[4] -> taille min, argv[5] -> taille max.
		size_t size = my_rand(atoi(argv[4]), atoi(argv[5]));
		int array[size];
		// On crée le tableau d'entier aléatoire, argv[2] -> valeur min, argv[3] -> valeur max.
		rand_array_int(array, atoi(argv[2]), atoi(argv[3]), size);
		display_array_int(array, size);
	}

	// 2
	if(atoi(argv[1]) == 9) {
		// On verifie qu'on est bien le bon nombre d'argument (falcutatif).
		if(argc != 4) {
			printf("Wrong number of arguments. Exiting...");
			return -1;
		}
		int a = atoi(argv[2]);
		int b = atoi(argv[3]);
		printf("Avant le swap -> a = %d, b = %d\n", a, b);
		swap(&a,&b);
		printf("Après le swap -> a = %d, b = %d\n", a, b);
	}

	// 3
	int array[5] = {5, 3, 1, 2, 2};
	printf("Avant le tri à bulle: ");
	display_array_int(array, 5);
	// Tri du tableau.
	bubble_sort_int(array, 5);
	printf("Après le tri à bulle: ");
	display_array_int(array, 5);

	// 4
	// On crée deux tableau non triés au pif.
	int arr_a[5] = {1, 10, 5, 4, 8};
	int arr_b[3] = {15, 6, 28};
	// On les trie
	bubble_sort_int(arr_a, 5);
	bubble_sort_int(arr_b, 3);
	// Prépare le pointeur qui va récuperer le nouveau tableau.
	int* merged_array;
	// On fusionne.
	merged_array = merge_sorted_int(arr_a, arr_b, 5, 3);
	// Affichage etc...
	display_array_int(arr_a, 5);
	printf(" + ");
	display_array_int(arr_b, 3);
	printf(" = ");
	display_array_int(merged_array, 5 + 3);
  free(merged_array);

	// 5
	int* draw_arr = loto(1, 49, 20);
	display_array_int(draw_arr, 20); 
	return 0;
}
