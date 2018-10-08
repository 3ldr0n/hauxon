#include <stdio.h>
#include <unistd.h>

#define PROGRAM "yes"

void usage(void);

int
main(int argc, char **argv)
{
	int opt;
	while ((opt = getopt(argc, argv, "h")) != -1) {
		switch (opt) {
		case 'h':
			usage();
			return 0;
		}
	}

	if (argc == 1) {
		for (;;)
			printf("y\n");
	} else {
		for (;;) {
			for (int i=1;i<argc;i++)
				printf("%s ", argv[i]);
			printf("\n");
		}
	}

	return 0;
}

void
usage(void)
{
	printf("Usage: yes [STRING]\n");
	printf("Repeatedly output a line with STRING, or just 'y'\n");
}
