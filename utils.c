#include "monty.h"

/**
 * initialize_global_vars - initializes the members of global_variables struct
 */
void initialize_global_vars(void)
{
	global_variables = (global_t *)malloc(sizeof(global_t));

	if (global_variables == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
	}
	global_variables->filePtr = NULL;
	global_variables->line = NULL;
	global_variables->command = NULL;
	global_variables->command_arg = NULL;
	global_variables->stack = NULL;
	global_variables->buffer = NULL;
	global_variables->line_number = 1;
}

/**
 * free_resources - handles the freeing of dynamically allcoated memory
 */
void free_resources(void)
{
	if (global_variables->filePtr != NULL)
	{
		fclose(global_variables->filePtr);
		global_variables->filePtr = NULL;
	}

	if (global_variables->line != NULL)
	{
		free(global_variables->line);
		global_variables->line = NULL;
	}

	if (global_variables->stack != NULL)
	{
		free_dlistint(global_variables->stack);
		global_variables->stack = NULL;
	}

	if (global_variables != NULL)
	{
		free(global_variables);
		global_variables = NULL;
	}
}

/**
 * isAllDigits - checks if all characters in a string are valid digits
 * @numStr: pointer to char representing the string to be checked
 * Return: 0 if any character is not a valid digit, 1 otherwise
 */
int isAllDigits(char *numStr)
{
	if (*numStr == '-' || *numStr == '+')
	{
		numStr++;
	}

	if (*numStr == '\0')
		return (0);

	while (*numStr != '\0')
	{
		if (isdigit(*numStr) == 0)
		{
			return (0);
		}
		numStr++;
	}
	return (1);
}
