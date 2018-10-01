#include <stdio.h>
#include <unistd.h>

#define PROGRAM "echo"

void usage(void);

void usage(void)
{
	printf("Usage:\n");
}

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
	if (argc == 1) {
		printf("\n");
	} else {
		for (int i=1;i<argc;i++)
			printf("%s ", argv[i]);
		printf("\n");
	}
		

	return 0;
}
