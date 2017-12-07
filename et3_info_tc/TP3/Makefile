all: TP3

TP3: main.o fonctions.o
	gcc  -lm -o TP3 main.o fonctions.o

main.o: main.c fonctions.h
	gcc -Wall -lm -o main.o -c main.c

fonctions.o: fonctions.c
	gcc -Wall -lm -o fonctions.o -c fonctions.c

clean:
	rm -f *.o

clean-all:
	rm -f *.o TP3
