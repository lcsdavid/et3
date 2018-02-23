#include "rand.h"

void my_srand() {
    srand(time(NULL));
}

int my_rand(int min, int max) {
    // Générateur congruentiel linéaire pour les curieux (cf. README.md)
    // On réduit le chiffre aléatoire à notre intervalle [min,max].
    return (int) (rand() / (double) RAND_MAX * (max - min - 1) + min);
}
