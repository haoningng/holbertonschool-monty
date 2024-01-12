#include "monty.h"

arg_t *arguments;

int main(int argc, char **argv)
{
	size_t n = 0;
	(void)argv;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	initialize_arguments();
	get_stream(argv[1]);

	while (getline(&arguments->line, &n, arguments->stream) != -1)
	{
		arguments->line_number += 1;
		// printf("Line %d: %s", arguments->line_number, arguments->line);
		tokenize_line();
		get_instruction();
		run_instruction();
		free_tokens();
	}

	close_stream();
	free_arguments();
	return (0);
}