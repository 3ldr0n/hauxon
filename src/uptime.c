#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define PROGRAM "uptime"

static int uptime(int pretty);
static void usage(void);

int main(int argc, char **argv)
{
	int opt;
	int pretty = 0;
	while ((opt = getopt(argc, argv, "ph")) != -1) {
		switch (opt) {
		case'p':
			pretty = 1;
			break;
		case 'h':
			usage();
			return 0;
		default:
			usage();
			exit(EXIT_FAILURE);
		}
	}

	int error = uptime(pretty);
	if (error) {
		return 1;
	}

	return 0;
}

static int uptime(int pretty)
{
	struct sysinfo info;
	int error = sysinfo(&info);
	if (error) {
		fprintf(stderr, "Code error: %d\n", error);
		return 1;
	}

	int hours = info.uptime / 3600;
	int minutes = info.uptime / 60 % 60;
	int seconds = info.uptime % 60;

	if (!pretty) {
		printf("Uptime: %d:%d:%d\n", hours, minutes, seconds);
		return 0;
	}

	if (hours > 24) {
		printf("Up %d days, %d hours and %d minutes\n", hours/24, hours%24, minutes);
	} else {
		printf("Up %d hours and %d minutes\n", hours, minutes);
	}

	return 0;
}

static void usage(void)
{
    printf("\nUsage: uptime [OPTIONS]\n");
    printf("Displays system uptime.\n");
    puts("\n");
    printf(" -p\tdisplays in a prettier way.\n");
    printf(" -h\tdisplays this help message.\n");
}
