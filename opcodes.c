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
	stack_t *new;
	int converted_arg;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (arg != NULL && isdigit(arg[0]) != 0)
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

/**
 * _pall - pushes an element to the stack.
 * @stack: doubly linked list to which the element is pushed
 * @line_number: the line number in the monty script
 *
 * Return: Nothing
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	(void)line_number;
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}