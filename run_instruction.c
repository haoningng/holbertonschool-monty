#include "monty.h"

void run_instruction(void)
{
	stack_t *stack = NULL;
	if (arguments->ntokens == 0)
		return;

	arguments->instruction->f(&stack, arguments->line_number);
}
