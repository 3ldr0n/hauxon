CC=tcc
CFLAGS=-std=c11 -Wall -I./include
SRC_DIR=src
BINDIR=bin
CAT_SRCS=cat.c
YES_SRCS=yes.c
ECHO_SRCS=echo.c
TRUE_SRCS=true.c
FALSE_SRCS=false.c

all: cat yes echo true false

%: $(SRC_DIR)/%.c
	mkdir -p bin
	$(CC) $(SRC_DIR)/$@.c $(CFLAGS) -o ./$(BINDIR)/$@

clean:
	rm bin/*
