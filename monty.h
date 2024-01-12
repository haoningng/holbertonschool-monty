#ifndef MONTY_H
#define MONTY_H

#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_var - global variables
 * @filePtr: the pointer to file
 * @line: pointer to each line (i.e. string)
 * @command: pointer opcode command
 * @command_arg: pointer the operands following the opcode
 * @stack: pointer to stack
 * @buffer: pointer to buffer
 * @line_number: line_number
 *
 * Description: global variables to be used in other files
 */
typedef struct global_var
{
	FILE *filePtr;
	char *line;
	char *command;
	char *command_arg;
	stack_t *stack;
	char *buffer;
	int line_number;
} global_t;

extern global_t *global_variables;

typedef void (*opcode_func)(stack_t **stack, unsigned int line_number);

/* monty.c */
void read_file(void);
/*void read_file(FILE *filePtr, stack_t **stack);*/
opcode_func get_op_func(char *str);

/* opcodes.c */
void _push(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);

/* opcodes_2.c */
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);

/* list_func.c */
stack_t *add_dnodeint_end(stack_t **head, const int n);
void add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/* utils.c */
void initialize_global_vars(void);
void free_resources(void);
int isAllDigits(char *);

#endif
