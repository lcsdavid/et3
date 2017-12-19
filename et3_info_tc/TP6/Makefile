
SRCs = $(wildcard *.c)
OBJs = $(SRCs:%.c=%.o)
CFLAGs = -Wall
LIBs = -lm

default: TP6

TP6: $(OBJs)
	gcc $(CFLAGs) -o TP6 $(OBJs) $(LIBs)
	
%.o: %.c
	gcc $(CFLAGs) -o $@ -c $<

clean:
	rm -f *.o TP6
