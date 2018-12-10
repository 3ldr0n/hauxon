#define _GNU_SOURCE

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

#define PROGRAM "head"

static void head(FILE *in, uint8_t n);
static FILE *fopen_s(char *filename, char *open_mode);

int main(int argc, char **argv)
{
	int opt;
	uint8_t n = 0;

	while ((opt = getopt(argc, argv, "n")) != -1) {
		switch (opt) {
		case 'n':
			n = 1;
			break;
		default:
			exit(EXIT_FAILURE);
		}
	}

	if (optind >= argc) {
		head(stdin, n);
		return 0;
	}

	char **file = &argv[optind];
	for ( ; *file ; file++) {
		FILE *fp = fopen_s(*file, "r");
		head(fp, n);
		fclose(fp);
	}

	return 0;
}

static FILE
*fopen_s(char *filename, char *open_mode)
{
	FILE *fp;
	fp = fopen(filename, open_mode);
	if (fp == NULL) {
		fprintf(stderr, "Can't acess file.\n");
		exit(EXIT_FAILURE);
	}

	return fp;
}

static void
head(FILE *in, uint8_t n)
{
	ssize_t read;
	char *buff = NULL;
	size_t size = 0;
	int i  = 1;

	while ((read = getline(&buff, &size, in)) != -1) {
		if (i == 11)
			break;

		if (n)
			printf("%d %s", i, buff);
		else
			printf("%s", buff);
		i++;
	}

	free(buff);
}
