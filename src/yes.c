#include <stdio.h>

#define PROGRAM "yes"

int main(int argc, char **argv)
{
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
