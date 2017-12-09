all: TP5

TP5: main.o string.o matrix.o utils.o
	gcc -g -o TP5 main.o string.o matrix.o utils.o

main.o: main.c string.h matrix.h utils.h
	gcc -g -Wall -o main.o -c main.c

string.o: string.c string.h utils.o utils.h
	gcc -g -Wall -o string.o -c string.c

matrix.o: matrix.c matrix.h utils.o utils.h
	gcc -g -Wall -o matrix.o -c matrix.c

utils.o: utils.c utils.h
	gcc -g -Wall -o utils.o -c utils.c

clean:
	rm -f *.o

clean-all:
	rm -f *.o TP4
