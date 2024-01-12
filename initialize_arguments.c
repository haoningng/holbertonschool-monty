#include "monty.h"

void initialize_arguments(void)
{
	arguments = malloc(sizeof(arg_t));

	if (arguments == NULL)
	{
		malloc_failed();
	}

	arguments->stream = NULL;
	arguments->line = NULL;
	arguments->head = NULL;
	arguments->line_number = 0;
	arguments->ntokens = 0;
	arguments->stack_length = 0;
}
