#include "monty.h"

void get_instruction(void)
{
	int i;

	instruction_t instructions[] = {
		{"push", &_push},
		{"pop", &_pop},
		{"pint", &_pint},
		{"swap", &_swap},
		{"nop", &_nop},
		{"add", &_add},
		{"pall", &_pall},
		{NULL, NULL}};

	if (arguments->ntokens == 0)
		return;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, arguments->tokens[0]) == 0)
		{
			arguments->instruction = malloc(sizeof(instruction_t));
			if (arguments->instruction == NULL)
				malloc_failed();

			arguments->instruction->opcode = instructions[i].opcode;
			arguments->instruction->f = instructions[i].f;

			return;
		}
	}

	invalid_instruction();
}
