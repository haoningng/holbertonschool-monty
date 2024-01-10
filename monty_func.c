#include "monty.h"

/**
 * read_file - reads a bytecode file and runs command
 */
void read_file(void)
{
	size_t n = 0;
	opcode_func func;
	global_t *gvars = global_variables;

	while (getline(&(gvars->buffer), &n, gvars->filePtr) != -1)
	{
		gvars->line = strtok(gvars->buffer, "\n");
		gvars->command = strtok(gvars->line, " $");

		if (gvars->command != NULL)
		{
			func = get_op_func(gvars->command);
			if (func == NULL)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n",
						gvars->line_number, gvars->command);
				free_resources();
				exit(EXIT_FAILURE);
			}
			else
			{
				gvars->command_arg = strtok(NULL, " $");
				func(&(gvars->stack), gvars->line_number);
				gvars->command_arg = NULL;
			}

			gvars->command = NULL;
		}
		(gvars->line_number)++;
	}
}

/**
 * get_op_func - checks opcode and return the right function
 * @str: the opcode
 *
 * Return: the function or NULL if failed
 */
opcode_func get_op_func(char *str)
{
	int i;
	instruction_t opcode_array[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{NULL, NULL}};
	i = 0;
	while (opcode_array[i].f != NULL && strcmp(opcode_array[i].opcode, str) != 0)
	{
		i++;
	}
	return (opcode_array[i].f);
}
