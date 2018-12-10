#include "cat.h"

int
main(int argc, char **argv)
{
	int opt;
	uint8_t n = 0;

	while ((opt = getopt(argc, argv, "nh")) != -1) {
		switch (opt) {
		case 'n':
			n = 1;
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
		cat(stdin, n);
		return 0;
	}

	char **file = &argv[optind];
	for ( ; *file ;file++) {
		FILE *fp = fopen_s(*file, "r");
		cat(fp, n);
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
		fprintf(stderr, "Can't access file.\n");
		exit(EXIT_FAILURE);
    }

	return fp;
}

static void
cat(FILE *in, uint8_t n)
{
	ssize_t read;
	char *buff = NULL;
	size_t size = 0;
	int i = 1;

	while ((read = getline(&buff, &size, in)) != -1) {
		if (n)
			printf("%d %s", i, buff);
		else
			printf("%s", buff);
		i++;
	}

	free(buff);
}

void
usage(void)
{
	printf("Usage: cat [OPTION] [FILE]\n");
	printf("Concatenate files to standard output.\n");
	puts("\n");
	printf(" -n\tnumber output lines\n");
	printf(" -h\tdisplays this help message\n");

	puts("\n");
	printf("Example:\n");
	printf("cat -n TestFile\n");
}
