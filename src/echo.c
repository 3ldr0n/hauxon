#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PROGRAM "echo"

static void usage(void);

int main(int argc, char **argv)
{
	int opt;
	int n = 0;
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
		if (!n)
			puts("\n");
		return 0;
	}

	char **words = &argv[optind];
	for ( ; *words ;words++)
		printf("%s ", *words);

	if (!n)
		printf("\n");
		
	return 0;
}

static void usage(void)
{
	printf("Usage: echo [OPTION] [STRING]\n");
	printf("Display a line of text.\n");
	puts("\n");
	printf(" -n\tdo not output the trailing newline\n");
	printf(" -h\tdisplays this help message\n");
	puts("\n");
	printf("Example:\n");
	printf("echo example message\n");
}
