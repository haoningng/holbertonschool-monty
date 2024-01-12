#include "monty.h"

void _pint(stack_t **stack, unsigned int line_number)
{
	(void)stack;

	if (arguments->head == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", arguments->head->n);
}