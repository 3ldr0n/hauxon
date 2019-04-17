CC=clang
CFLAGS+=-Wall -Wextra -Werror
SRC_DIR=src
BIN_DIR=bin

all: cat yes echo true false head tail uptime free tac

%: $(SRC_DIR)/%.o
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/$@.o -o ./$(BIN_DIR)/$@

.PRECIOUS: %.o

.PHONY: clean

clean:
	rm $(BIN_DIR)/*
	rm $(SRC_DIR)/*.o
