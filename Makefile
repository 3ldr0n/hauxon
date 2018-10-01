CC=tcc
CFLAGS=-std=c11 -Wall -I../include
DEPS=cat.h
CAT_OBJ=cat.o
CAT_SRCS=cat.c
YES_SRCS=yes.c
ECHO_SRCS=echo.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all:
	mkdir -p bin
	cd src/ && $(CC) $(CAT_SRCS) $(CFLAGS) -o ../bin/cat
	cd src/ && $(CC) $(YES_SRCS) $(CFLAGS) -o ../bin/yes
	cd src/ && $(CC) $(ECHO_SRCS) $(CFLAGS) -o ../bin/echo

cat:
	mkdir -p bin
	cd src/ && $(CC) $(CAT_SRCS) $(CFLAGS) -o ../bin/cat

yes:
	mkdir -p bin
	cd src/ && $(CC) $(YES_SRCS) $(CFLAGS) -o ../bin/yes

echo:
	mkdir -p bin
	cd src/ && $(CC) $(ECHO_SRCS) $(CFLAGS) -o ../bin/echo

clean:
	rm -rf bin
