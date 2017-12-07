all: TP1

TP1: main.o affichage.o
	gcc -o TP1 main.o affichage.o

main.o: main.c affichage.h
	gcc -Wall -o main.o -c main.c

affichage.o: affichage.c
	gcc -Wall -o affichage.o -c affichage.c

clean:
	rm -f *.o
