CC=gcc
CFLAGS=-std=c11 -Wall -I../include
DEPS=malloc_s.h
CAT_OBJ=malloc_s.o cat.o
CAT_SRCS=malloc_s.c cat.c
YES_SRCS=yes.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cat:
	mkdir -p bin
	cd src/ && $(CC) $(CAT_SRCS) $(CFLAGS) -o ../bin/cat

yes:
	mkdir -p bin
	cd src/ && $(CC) $(YES_SRCS) $(CFLAGS) -o ../bin/yes

clean:
	rm -rf bin
