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
	stack_t *stack;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_file(argv[1], &stack);
	/*	free_dlistint(stack); */
	return (0);
}
