all: TP5

TP5: main.o string.o
	gcc -o TP5 main.o string.o

main.o: main.c string.h
	gcc -Wall -o main.o -c main.c

string.o: string.c
	gcc -Wall -o string.o -c string.c

clean:
	rm -f *.o

clean-all:
	rm -f *.o TP4
