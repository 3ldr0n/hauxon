CC=tcc
CFLAGS=-std=c11 -Wall -I./include
SRC_DIR=src
BIN_DIR=bin
CAT_SRCS=cat.c
YES_SRCS=yes.c
ECHO_SRCS=echo.c
TRUE_SRCS=true.c
FALSE_SRCS=false.c

all: cat yes echo true false

%: $(SRC_DIR)/%.o
	mkdir -p bin
	$(CC) $(SRC_DIR)/$@.o $(CFLAGS) -o ./$(BIN_DIR)/$@

.PRECIOUS: %.o

clean:
	rm bin/*
	rm src/*.o
