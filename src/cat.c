#define _GNU_SOURCE
#include "common.h"
#include <string.h>

#define PROGRAM "cat"
#define MAX_BUFFER_SIZE 32

static FILE *fopen_s(char *filename, char *open_mode);
static void cat(FILE *in, FILE *out);

static FILE
*fopen_s(char *filename, char *open_mode)
{
	FILE *fp;
    fp = fopen(filename, open_mode);
    if (fp == NULL) {
		fprintf(stderr, "Can't access file.\n");
		exit(-1);
    }

	return fp;
}

static void cat(FILE *in, FILE *out)
{
	ssize_t read;
	char *buff = NULL;
	size_t size = 0;
	int i = 0;

	while ((read = getline(&buff, &size, in)) != -1) {
		fprintf(out, "%s", buff);
		i++;
	}

	free(buff);
}

int main(int argc, char **argv)
{
	if (argc == 1) {
		cat(stdin, stdout);
		return 0;
	}

	FILE *fp;

	if (argc == 2) {
		fp = fopen_s(argv[1], "r");
		cat(fp, stdout);
		fclose(fp);
	} else if (argc == 4) {
		if (strcmp(">>", argv[2]) != 0) {
			for (int i=0;i<argc;i++) {
				fp = fopen_s(argv[i], "r");
				cat(fp, stdout);
				fclose(fp);
			}
			return 0;
		}
		FILE *fpout;
		fp = fopen_s(argv[1], "r");
		fpout = fopen_s(argv[3], "r");
		cat(fp, fpout);
		fclose(fpout);
		fclose(fp);
	} else {
		for (int i=1;i<argc;i++) {
			fp = fopen_s(argv[i], "r");
			cat(fp, stdout);
			fclose(fp);
		}
	}

    return 0;
}
