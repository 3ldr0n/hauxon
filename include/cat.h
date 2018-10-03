#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PROGRAM "cat"
#define MAX_BUFFER_SIZE 32

static FILE *fopen_s(char *filename, char *open_mode);
static void cat(FILE *in, FILE *out, int n);
void usage(void);