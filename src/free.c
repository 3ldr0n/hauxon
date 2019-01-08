#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define PROGRAM "free"

void usage(void);
void xfree(int unit);

int main(int argc, char **argv)
{
    int opt;
    int unit = 1;
    while ((opt = getopt(argc, argv, "m")) != -1) {
        switch (opt) {
        case 'm':
            unit = 1024;
            break;
        default:
            usage();
            exit(EXIT_FAILURE);
        }
    }

    xfree(unit);

	return 0;
}

/**
 * Displays the amount of free/used memory.
 * unit parameter decides in which format the memory will be displayed.
 */
void xfree(int unit)
{
	struct sysinfo info;
	int error = sysinfo(&info);
	if (error) {
		fprintf(stderr, "Code error: %d\n", error);
		exit(EXIT_FAILURE);
	}

    uint64_t totalram = (info.totalram * info.mem_unit) / 1024;
    uint64_t freeram = (info.freeram * info.mem_unit) / 1024;
    uint64_t bufferram = (info.bufferram * info.mem_unit) / 1024;

    uint64_t totalswap = (info.totalswap * info.mem_unit) / 1024;
    uint64_t freeswap = (info.freeswap * info.mem_unit) / 1024;

    uint64_t usedram = totalram - freeram - bufferram;
    uint64_t usedswap = totalswap - freeswap;

    printf("\ttotal\tfree\tused\n");
    printf("Mem:\t%lu\t%lu\t%lu\n",
           totalram/unit, freeram/unit, usedram/unit);

    printf("Swap:\t%lu\t%lu\t%lu\n",
           totalswap/unit, freeswap/unit, usedswap/unit);
}

void usage(void)
{
    printf("Usage: free [OPTIONS]\n");
    printf("Shows amount of memory is being used.\n");
    puts("\n");
    printf(" -m\tdisplay numbers in megibytes.\n");
}
