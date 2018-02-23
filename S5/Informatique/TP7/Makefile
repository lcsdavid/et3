
SRCs = $(wildcard *.c)
OBJs = $(SRCs:%.c=%.o)
CFLAGs = -Wall
#LIBs = -lm

default: TP7

TP7: $(OBJs)
	gcc $(CFLAGs) -o TP7 $(OBJs) $(LIBs)
	
%.o: %.c
	gcc $(CFLAGs) -o $@ -c $<

clean:
	rm -f *.o TP7
