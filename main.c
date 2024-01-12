#include "monty.h"

global_t *global_variables = NULL;

/**
 * main - entry point
 * @argc: number of variable arguments
 * @argv: the array of arguments
 *
 * Return: 0 if successful
 */
int main(int argc, char **argv)
{

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	initialize_global_vars();
	global_variables->filePtr = fopen(argv[1], "r");

	if (global_variables->filePtr == NULL)
	{
		fprintf(stderr, "Error: Can't open file '%s'\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	read_file();
	free_resources();
	return (0);
}
