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

cat:
	mkdir -p bin
	$(CC) src/$(CAT_SRCS) $(CFLAGS) -o ./$(BINDIR)/cat

yes:
	mkdir -p bin
	$(CC) src/$(YES_SRCS) $(CFLAGS) -o ./$(BINDIR)/yes

echo:
	mkdir -p bin
	$(CC) src/$(ECHO_SRCS) $(CFLAGS) -o ./$(BINDIR)/echo

true:
	mkdir -p bin
	$(CC) src/$(TRUE_SRCS) $(CFLAGS) -o ./$(BINDIR)/true

false:
	mkdir -p bin
	$(CC) src/$(FALSE_SRCS) $(CFLAGS) -o ./$(BINDIR)/false

clean:
	rm bin/*
