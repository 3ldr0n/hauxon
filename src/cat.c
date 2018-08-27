#include "malloc_s.h"

#define PROGRAM "cat"
#define MAX_BUFFER_SIZE 32

void read_file_content(FILE *in, FILE *out)
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
	FILE *fp;

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
		fprintf(stderr, "Can't access file.\n");
		return -1;
    }

    read_file_content(fp, stdout);

    fclose(fp);

    return 0;
}
