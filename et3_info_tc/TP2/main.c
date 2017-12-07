#include<stdio.h>
#include<stdlib.h>

int mirror_effect(int v) {
    int result = 0, expo = 1;
    while(v / expo != 0) {
        result *= 10;
        result += (v / expo) % 10;
        expo *= 10;
    }
    return result;
}

/** j: 0 h: 1 m: 2 s: 3 **/
int * stojhms(long s) {
    int * jhms = malloc(4 * sizeof(int));
    jhms[0] = s / 86400;
    jhms[1] = (s - jhms[0] * 86400) / 3600;
    jhms[2] = (s - jhms[0] * 86400 - jhms[1] * 3600) / 60;
    jhms[3] = (s - jhms[0] * 86400 - jhms[1] * 3600 - jhms[2] * 60);
    return jhms;
}

void max_sequence() {
    int i = 1;
    int index = 1;
    int max = 0;
    while(1) {
      int number;
      printf("Entrez le nombre %d: \n", i);
      scanf("%d", &number);
      if(number == 0)
       break;
      if(number > max) {
        max = number;
        index = i;
      }
      i++;
    }
    printf("Le plus grand de ces nombres est: %d. C'était le %dième nombre saisi.\n", max, index);
}

void euclidean_division(int dividend, int divisor) {
  if(divisor == 0)
    exit(0);
  int quotient = 0;
  while(dividend > divisor) {
    dividend -= divisor;
    quotient++;
  }
  printf("%d / %d = %d avec un reste = %d.\n", quotient * divisor + dividend, divisor, quotient, dividend);
}

int my_rand(long seed, int min, int max) {
  return ((seed * 984321065 + 514561) % 1981489198) % (max - min) + min;
}

void loto() {
  int n;
  printf("Combien de fois tu tires?\n");
  scanf("%d", &n);
  int values[n];
  for(size_t i = 0; i < n; i++)
    values[i] = my_rand(i, 1, 49);
  for(size_t i = 0; i < n; i++)
    printf("Tirage numéro %lu: %d\n", i + 1, values[i]);
}

int main() {
    // 1.
    printf("%d\n", mirror_effect(5896));

    // 2.
    int * t = stojhms(562430);
    printf("%d secondes = %d jours %d heures %d minutes %d secondes.\n", 562430, t[0], t[1], t[2], t[3]);
    free(t);

    // 3.
    max_sequence();

    // 4.
    euclidean_division(5, 4);

    // 5.
    loto();
    return 0;
}
