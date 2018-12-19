CC=tcc
CFLAGS=-std=c11 -Wall -Wextra
SRC_DIR=src
BIN_DIR=bin

all: cat yes echo true false head

%: $(SRC_DIR)/%.o
	mkdir -p $(BIN_DIR)
	$(CC) $(SRC_DIR)/$@.o $(CFLAGS) -o ./$(BIN_DIR)/$@

.PRECIOUS: %.o

.PHONY: clean
clean:
	rm $(BIN_DIR)/*
	rm $(SRC_DIR)/*.o
