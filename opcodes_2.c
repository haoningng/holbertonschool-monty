#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack.
 * @stack: doubly linked list from which 2 elements are swapped
 * @line_number: the line number in the monty script
 *
 * Return: Nothing
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	if (line_number < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_resources();
		exit(EXIT_FAILURE);
	}

	stack_t *temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->prev = temp->prev;
	(*stack)->next = temp;
	temp->prev = *stack;
}

/**
 * _add - adds the top two elements of the stack
 * @stack: doubly linked list from which top 2 elements are added and merged
 * @line_number: the line number in the monty script
 *
 * Return: Nothing
 */
void _add(stack_t **stack, unsigned int line_number)
{
	/*TODO*/
/*	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop and empty stack\n", line_number);
		free_resources();
		exit(EXIT_FAILURE);
	}

	stack_t *temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);*/
	(void)stack;
	(void)line_number;
}

/**
 * _nop - doesn’t do anything
 * @stack: doubly linked list
 * @line_number: the line number in the monty script
 *
 * Return: Nothing
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

