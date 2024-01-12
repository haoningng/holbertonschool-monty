#include "monty.h"

void free_arguments(void)
{
	if (arguments == NULL)
		return;

	if (arguments->instruction)
	{
		free(arguments->instruction);
		arguments->instruction = NULL;
	}

	if (arguments->line)
	{
		free(arguments->line);
		arguments->line = NULL;
	}

	free_head();
	free(arguments);
}
