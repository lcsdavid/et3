ifeq ($(OS), Windows_NT)
    TARGET := pgm.exe
else 
	UNAME := $(shell uname -s)
	ifeq ($(UNAME), Darwin)
		TARGET := pgm.app
	else ifeq ($(UNAME), Linux)
		TARGET := pgm
	endif
endif

CFLAGs := -Wall -O3

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

SRCs := $(wildcard $(SRC_DIR)/*.c)
OBJs := $(SRCs:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

default: $(TARGET)

$(TARGET): $(OBJs)
	gcc $(CFLAGs) -o $@ $(OBJs)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc $(CFLAGs) -o $@ -c $<

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)
