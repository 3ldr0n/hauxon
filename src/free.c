#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

int main(int argc, char **argv)
{

	struct sysinfo sys;
	int error = sysinfo(&sys);
	if (error) {
		fprintf(stderr, "Code error: %d\n", error);
		exit(EXIT_FAILURE);
	}

	printf("\t\ttotal\t\tfree\n");
	printf("Mem:\t\t%lu\t%lu\n", sys.totalram, sys.freeram);
	printf("Swap:\t\t%lu\t%lu\n", sys.totalswap, sys.freeswap);

	return 0;
}
