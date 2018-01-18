
SRCs = $(wildcard *.c)
OBJs = $(SRCs:%.c=%.o)
CFLAGs = -Wall
#LIBs = -lm

default: TP9

TP9: $(OBJs)
	gcc $(CFLAGs) -o TP9 $(OBJs) $(LIBs)

%.o: %.c
	gcc $(CFLAGs) -o $@ -c $<

clean:
	rm -f *.o TP9
