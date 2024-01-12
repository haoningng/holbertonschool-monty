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

typedef struct arg_s
{
        FILE *stream;
        char *line;
        unsigned int line_number;
        char **tokens;
        int ntokens;
        instruction_t *instruction;
        stack_t *head;
        unsigned int stack_length;
} arg_t;

extern arg_t *arguments;

void malloc_failed(void);
void initialize_arguments(void);
void getting_stream_failed(char *filename);
void get_stream(char *filename);
void free_arguments(void);
void tokenize_line(void);
void get_instruction(void);
void run_instruction(void);
void free_tokens(void);
void close_stream(void);
void free_arguments(void);
void _push(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void invalid_instruction(void);
void free_head(void);
void free_stack(stack_t *head);
int is_number(char *);
void free_all_args(void);
void delete_stack_node(void);
#endif