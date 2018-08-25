#include "malloc_s.h"

void *malloc_s(size_t size)
{
	if (!size)
		return NULL;

	void *mem;
	mem = malloc(size);

	if (!mem) {
		fprintf(stderr, "Fatal: memory exhausted (malloc of %zu bytes)\n", size);
		exit(-1);
	}

	return mem;
}
