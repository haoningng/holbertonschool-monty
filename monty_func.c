#include "monty.h"

size_t BUFFER_LENGTH = 2064;
char *arg = NULL;

/**
 * read_file - reads a bytecode file and runs command
 * @filename: pathname to file
 * @stack: pointer to the top of the stack
 */
void read_file(FILE *filePtr, stack_t **stack)
{

	char *buffer = NULL, *line;
	char *command = NULL;
	size_t n = 0;
	int line_number = 1;
	opcode_func func;

	while (getline(&buffer, &n, filePtr) != -1)
	{
		line = strtok(buffer, "\n");
		(void)line;
		command = strtok(buffer, " $");

		if (command != NULL)
		{
			func = get_op_func(command);
			if (func == NULL)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, command);
				free(buffer);
				buffer = NULL;
				fclose(filePtr);
				free_dlistint(*stack);
				exit(EXIT_FAILURE);
			}
			else
			{
				arg = strtok(NULL, " $");
				func(stack, line_number);
				arg = NULL;
			}
			command = NULL;
		}
		line_number++;
	}

	(void)func;
	(void)stack;
	if (buffer != NULL)
	{
		free(buffer);
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
		/*{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop}, */
		{NULL, NULL}};
	i = 0;
	while (opcode_array[i].f != NULL && strcmp(opcode_array[i].opcode, str) != 0)
	{
		i++;
	}
	return (opcode_array[i].f);
}
