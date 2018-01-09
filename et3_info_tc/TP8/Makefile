
SRCs = $(wildcard *.c)
OBJs = $(SRCs:%.c=%.o)
CFLAGs = -Wall
#LIBs = -lm

default: TP8

TP8: $(OBJs)
	gcc $(CFLAGs) -o TP8 $(OBJs) $(LIBs)
	
%.o: %.c
	gcc $(CFLAGs) -o $@ -c $<

clean:
	rm -f *.o TP8
