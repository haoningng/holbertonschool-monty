#include "monty.h"

/**
 * _push - pushes an element to the stack.
 * @stack: doubly linked list to which the element is pushed
 * @line_number: the line number in the monty script
 *
 * Return: Nothing
 */
void _push(stack_t **stack, unsigned int line_number)
{
	char *arg = global_variables->command_arg;
	int converted_arg;

	if (arg == NULL || isdigit(arg[0]) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_resources();
		exit(EXIT_FAILURE);
	}
	else
	{
		converted_arg = atoi(arg);
		add_dnodeint(stack, converted_arg);
	}
}

/**
 * _pop - pushes an element to the stack.
 * @stack: doubly linked list from which the element is popped
 * @line_number: the line number in the monty script
 *
 * Return: Nothing
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop and empty stack\n", line_number);
		free_resources();
		exit(EXIT_FAILURE);
	}

	stack_t *temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
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

/**
 * _pint - prints the element at the top of the stack.
 * @stack: doubly linked list to which the element is pushed
 * @line_number: the line number in the monty script
 *
 * Return: Nothing
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_resources();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
