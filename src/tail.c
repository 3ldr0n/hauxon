#define _GNU_SOURCE

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PROGRAM "head"

static void tail(FILE *in);
static FILE *fopen_s(char *filename, char *open_mode);

int main(int argc, char **argv)
{
    int opt;

    while ((opt = getopt(argc, argv, "n")) != -1) {
        switch (opt) {
        default:
            exit(EXIT_FAILURE);
        }
    }

    if (optind >= argc) {
        tail(stdin);
        return 0;
    }

    char **file = &argv[optind];
    for ( ; *file ; file++) {
        FILE *fp = fopen_s(*file, "r");
        tail(fp);
        fclose(fp);
    }

    return 0;
}

static FILE
*fopen_s(char *filename, char *open_mode)
{
    FILE *fp;
    fp = fopen(filename, open_mode);
    if (fp == NULL) {
        fprintf(stderr, "Can't acess file.\n");
        exit(EXIT_FAILURE);
    }

    return fp;
}

static void
tail(FILE *in)
{
    ssize_t read;
    char *buff = NULL;
    size_t size = 0;
    char **file_content = NULL;

    int i  = 0;
    while ((read = getline(&buff, &size, in)) != -1) {
        file_content = (char **)realloc(file_content, (i + 1) * sizeof(char *));
        file_content[i] = (char *)calloc(sizeof(char), strlen(buff));

        strcpy(file_content[i], buff);
        i++;
    }

    for (int j = (i-10);j < i;j++) {
        printf("%s", file_content[j]);
    }
}
