#include <stdio.h>

int main(int argc, int **argv)
{
	for (;;) {
		printf("%s\n", argv[1]);
	}

	return 0;
}
