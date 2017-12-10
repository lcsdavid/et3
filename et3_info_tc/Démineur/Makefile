
SRCsDIR = src
OBJsDIR = obj
BINsDIR = bin

SRCs = $(wildcard $(SRCsDIR)/*.c)
OBJs = $(SRCs:$(SRCsDIR)/%.c=$(OBJsDIR)/%.o)
LIBs = -lncurses
CFLAGs = -Wall

default: Démineur

Démineur: $(OBJs)
	gcc $(CFLAGs) -o $(BINsDIR)/Démineur $(OBJs) $(LIBs)

$(OBJsDIR)/%.o: $(SRCsDIR)/%.c
	gcc $(CFLAGs) -o $@ -c $<
	
clean:
	rm -f obj/*.o Démineur
