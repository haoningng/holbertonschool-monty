#include "monty.h"

/**
 * main - entry point
 * @argc: number of variable arguments
 * @argv: the array of arguments
 *
 * Return: 0 if successful
 */
int main(int argc, char **argv)
{
	FILE *filePtr;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filePtr = fopen(argv[1], "r");

	if (filePtr == NULL)
	{
		fprintf(stderr, "Error: Can't open file '%s'\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	read_file(filePtr, &stack);
	free_dlistint(stack);
	fclose(filePtr);
	return (0);
}
