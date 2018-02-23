default: TP4

TP4: main.o tableau.o rand.o
	gcc -o TP4 main.o tableau.o rand.o

main.o: main.c tableau.h rand.h
	gcc -Wall -o main.o -c main.c

tableau.o: tableau.c rand.h
	gcc -Wall -o tableau.o -c tableau.c

rand.o: rand.c
	gcc -Wall -o rand.o -c rand.c

clean:
	rm -f *.o

clean-all:
	rm -f *.o TP4
