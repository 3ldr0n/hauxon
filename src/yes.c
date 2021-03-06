#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PROGRAM "yes"

static void usage(void);
void yes(int argc, char **argv);

int main(int argc, char **argv)
{
	int opt;
	while ((opt = getopt(argc, argv, "h")) != -1) {
		switch (opt) {
		case 'h':
			usage();
			return 0;
		default:
			usage();
			exit(EXIT_FAILURE);
		}
	}

    yes(argc, argv);
	return 0;
}

void yes(int argc, char **argv)
{
	if (argc == 1) {
		for (;;)
			printf("y\n");
	} else {
		for (;;) {
			for (int i = 1;i < argc;i++)
				printf("%s ", argv[i]);
			printf("\n");
		}
	}
}

static void usage(void)
{
	printf("Usage: yes [STRING]\n");
	printf("Repeatedly output a line with STRING, or just 'y'\n");
}
