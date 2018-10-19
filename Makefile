CC=tcc
CFLAGS=-std=c11 -Wall -I../include
SRC_DIR=src
BIN_DIR=bin
CAT_SRCS=cat.c
YES_SRCS=yes.c
ECHO_SRCS=echo.c
TRUE_SRCS=true.c
FALSE_SRCS=false.c

%: src/%.c
	$(CC) $(CFLAGS) $< -o $(BIN_DIR)/$@

all: cat yes echo true false

cat:
	mkdir -p bin
	cd src/ && $(CC) $(CAT_SRCS) $(CFLAGS) -o ../$(BIN_DIR)/cat

yes:
	mkdir -p bin
	cd src/ && $(CC) $(YES_SRCS) $(CFLAGS) -o ../$(BIN_DIR)/yes

echo:
	mkdir -p bin
	cd src/ && $(CC) $(ECHO_SRCS) $(CFLAGS) -o ../$(BIN_DIR)/echo

true:
	mkdir -p bin
	cd src/ && $(CC) $(TRUE_SRCS) $(CFLAGS) -o ../$(BIN_DIR)/true

false:
	mkdir -p bin
	cd src/ && $(CC) $(FALSE_SRCS) $(CFLAGS) -o ../$(BIN_DIR)/false

clean:
	rm bin/*
