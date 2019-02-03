CC=gcc
CFLAGS+=-Wall -Wextra
SRC_DIR=src
BIN_DIR=bin

all: cat yes echo true false head uptime free

%: $(SRC_DIR)/%.o
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/$@.o -o ./$(BIN_DIR)/$@

.PRECIOUS: %.o

.PHONY: clean

clean:
	rm $(BIN_DIR)/*
	rm $(SRC_DIR)/*.o
