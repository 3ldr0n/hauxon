#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

int main(int argc, char **argv)
{
	struct sysinfo info;
	int error = sysinfo(&info);
	if (error) {
		fprintf(stderr, "Code error: %d\n", error);
		exit(EXIT_FAILURE);
	}

	printf("\t\ttotal\t\tfree\n");
	printf("Mem:\t\t%lu\t%lu\n", info.totalram, info.freeram);
	printf("Swap:\t\t%lu\t%lu\n", info.totalswap, info.freeswap);

	return 0;
}
