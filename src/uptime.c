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

	int hours = info.uptime / 3600;
	int minutes = info.uptime / 60 % 60;
	int seconds = info.uptime % 60;

	printf("Uptime: %d:%d:%d\n", hours, minutes, seconds);

	return 0;
}
