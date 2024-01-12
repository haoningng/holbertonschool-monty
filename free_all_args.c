#include "monty.h"

void free_all_args(void)
{
	close_stream();
	free_tokens();
	free_arguments();
}
