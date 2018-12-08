#ifndef CAT_H
#define CAT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <features.h>

#define _POSIX_C_SOURCE >= 200809L || _XOPEN_SOURCE >= 700

#define PROGRAM "cat"

static FILE *fopen_s(char *filename, char *open_mode);
static void cat(FILE *in, uint8_t n);
void usage(void);

#endif