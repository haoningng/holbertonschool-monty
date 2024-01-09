#include "monty.h"

size_t BUFFER_LENGTH = 2064;
char *arg = NULL;

/**
 * read_file - reads a bytecode file and runs command
 * @filename: pathname to file
 * @stack: pointer to the top of the stack
 */
void read_file(char *filename, stack_t **stack)
{
	FILE *stream = fopen(filename, "r");
        char *buffer = NULL, *line, *token;
	size_t n = 0;
	int line_number = 1;
	opcode_func func;

	/*
        if (fd == -1)
        {
                fprintf(stderr, "Error: Can't open file %s\n", filename);
                exit(EXIT_FAILURE);
        }
        buffer = malloc(sizeof(char) * BUFFER_LENGTH);
        if (buffer == NULL)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }
        cnt = read(fd, buffer, BUFFER_LENGTH);
        if (cnt < 0)
        {
                free(buffer);
                close(fd);
                fprintf(stderr, "Error reading file\n");
                exit(EXIT_FAILURE);
        }
        token = strtok(buffer, "\n $");
        while(token != NULL)
        {
                printf("%s\n", token);
                token = strtok(NULL, "\n $");
        }*/
	while (getline(&buffer, &n, stream) != -1)
	{
		line = strtok(buffer, "\n");
		(void) line;
		token = strtok(buffer, " $");
		while(token != NULL)
        	{
                	func = get_op_func(token);
			if (func == NULL)
			{
				printf("func is null\n");
				break;
			}
			else
			{
				printf("func is not null\n");
				printf("%s\n", token);
				token = strtok(NULL, " $");
				arg = token;
				_push(stack, line_number);
			}
        	}
		line_number++;
	}
	(void) func;
	(void) stack;
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
        instruction_t opcode_array[]= {
                {"push", _push},
       /*         {"pall", _pall},
                {"pint", _pint},
                {"pop", _pop},
                {"swap", _swap},
                {"add", _add},
                {"nop", _nop}, */
                {NULL, NULL}
        };
	i = 0;
	while (opcode_array[i].f != NULL && strcmp(opcode_array[i].opcode, str) != 0)
	{
		i++;
	}
	return(opcode_array[i].f);
}
