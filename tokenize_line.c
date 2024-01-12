#include "monty.h"

void tokenize_line(void)
{
	int i = 0;
	char *delimiters = " \n$", *token = NULL, *line_copy = NULL;

	line_copy = malloc(strlen(arguments->line) + 1);
	if (line_copy == NULL)
		malloc_failed();

	strcpy(line_copy, arguments->line);
	arguments->ntokens = 0;
	token = strtok(line_copy, delimiters);
	while (token)
	{
		arguments->ntokens += 1;
		token = strtok(NULL, delimiters);
	}

	arguments->tokens = malloc(sizeof(char *) * (arguments->ntokens + 1));

	if (arguments->tokens == NULL)
		malloc_failed();

	strcpy(line_copy, arguments->line);
	token = strtok(line_copy, delimiters);
	while (token)
	{
		arguments->tokens[i] = strdup(token);
		token = strtok(NULL, delimiters);
		i++;
	}
	arguments->tokens[i] = NULL;
	free(line_copy);
}