#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#define PROGRAM "head"

static void head(FILE *in, bool n);
static FILE *fopen_s(char *filename, char *open_mode);
static void usage(void);

int main(int argc, char **argv)
{
	int opt;
	bool n = false;

	while ((opt = getopt(argc, argv, "nh")) != -1) {
		switch (opt) {
		case 'n':
			n = true;
			break;
        case 'h':
            usage();
            return 0;
		default:
            usage();
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

static FILE *fopen_s(char *filename, char *open_mode)
{
	FILE *fp;
	fp = fopen(filename, open_mode);
	if (fp == NULL) {
		fprintf(stderr, "Can't acess file.\n");
		exit(EXIT_FAILURE);
	}

	return fp;
}

static void head(FILE *in, bool n)
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

static void usage(void)
{
    printf("Usage: head [OPTION] [FILE]\n");
	printf("Displays first ten lines of a file.\n");
	puts("\n");
	printf(" -n\tnumber output lines\n");
	printf(" -h\tdisplays this help message\n");
}
