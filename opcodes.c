#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: doubly linked list to which the element is pushed
 * @line_number: the line number in the monty script
 *
 * Return: Nothing
 */
void _push(stack_t **stack, unsigned int line_number)
{
	printf("testing..");
	stack_t *new;
	int converted_arg;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (isdigit(arg) == 0 && arg != NULL)
	{
		converted_arg = atoi(arg);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	add_dnodeint(stack, converted_arg);
}
