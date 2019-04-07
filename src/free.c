#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define PROGRAM "free"

static void usage(void);
static void xfree(int unit);
static void pretty_free();

int main(int argc, char **argv)
{
    int opt;
    int unit = 1;
    while ((opt = getopt(argc, argv, "kmgh")) != -1) {
        switch (opt) {
        case 'k':
            break;
        case 'm':
            unit = 1024;
            break;
        case 'g':
            unit = 1024*1024;
            break;
		case 'h':
			pretty_free();
			return 0;
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
static void xfree(int unit)
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

static void pretty_free()
{
	int unit = 1024*1024;
	struct sysinfo info;
	int error = sysinfo(&info);
	if (error) {
		fprintf(stderr, "Code error: %d\n", error);
		exit(EXIT_FAILURE);
	}

    float totalram = (info.totalram * info.mem_unit) / 1024;
    float freeram = (info.freeram * info.mem_unit) / 1024;
    float bufferram = (info.bufferram * info.mem_unit) / 1024;

    float totalswap = (info.totalswap * info.mem_unit) / 1024;
    float freeswap = (info.freeswap * info.mem_unit) / 1024;

    float usedram = totalram - freeram - bufferram;
    float usedswap = totalswap - freeswap;

    printf("\ttotal\tfree\tused\n");
    printf("Mem:\t%.2fG\t%.2fG\t%.2fG\n",
           totalram/unit, freeram/unit, usedram/unit);

    printf("Swap:\t%.2fG\t%.2fG\t%.2fG\n",
           totalswap/unit, freeswap/unit, usedswap/unit);
}

static void usage(void)
{
    printf("\nUsage: free [OPTIONS]\n");
    printf("Shows amount of memory is being used.\n");
    puts("\n");
    printf(" -k\tdisplay numbers in kibibytes.\n");
    printf(" -m\tdisplay numbers in megibytes.\n");
    printf(" -g\tdisplay numbers in gibibytes.\n");
    printf(" -h\tdisplay numbers in a pretty way.\n");
}
