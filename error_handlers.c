#include "monty.h"

void malloc_failed(void)
{
	dprintf(2, "Error: malloc failed\n");
	free_arguments();
	exit(EXIT_FAILURE);
}

void getting_stream_failed(char *filename)
{
	dprintf(2, "Error: Can't open file %s\n", filename);
	free_arguments();
	exit(EXIT_FAILURE);
}