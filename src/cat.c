#include "malloc_s.h"

#define PROGRAM "cat"
#define MAX_BUFFER_SIZE 32

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

static void
read_file_content(FILE *in, FILE *out)
{
    char *buff = malloc_s(MAX_BUFFER_SIZE);

    size_t size;
    while ((size = fread(buff, 1, MAX_BUFFER_SIZE, in)) != 0) {
		fwrite(buff, 1, size, out);
    }

    free(buff);
}

int main(int argc, char **argv)
{
	if (argc == 1) {
		read_file_content(stdin, stdout);
		return 0;
	}

	FILE *fp;

	if (argc == 2) {
		fp = fopen_s(argv[1], "r");
		read_file_content(fp, stdout);
		fclose(fp);
	} else if (argc == 4) {
		FILE *fpout;
		fp = fopen_s(argv[1], "r");
		fpout = fopen_s(argv[3], "r");
		read_file_content(fp, fpout);
		fclose(fpout);
		fclose(fp);
	} else {
		for (int i=1;i<argc;i++) {
			fp = fopen_s(argv[i], "r");
			read_file_content(fp, stdout);
			fclose(fp);
		}
	}

    return 0;
}
