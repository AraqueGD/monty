#ifndef MONTY_H
#define MONTY_H

/**
 * headers_files - C standard libraries headers
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

/* Define Macros */
#define DELIMITERS "\n\t\r "

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_variables - data structure for some global variables
 * @opc_code: hold the intruction(push, pop, pall...)
 * @val_arg: hold the argument of opc_code
 * @error_in_func: true if there was an error or otherwise false
 */
typedef struct global_variables
{
	char *opc_code;
	char *val_arg;
	bool error_in_func;
} info_t;

/* Global variable - Declaration and Initialization */
extern info_t info;
info_t info;

/* Principal functions of monty interpreter */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);

/* Stack functions */
int init_stack(stack_t **top);
void free_stack(stack_t **top);

/* Error Message Functions */
int error_usage_file(void);
int error_open_file(char *fileptr);
int error_malloc(void);
int error_no_integer(unsigned int line_number);
int error_unknown_instruction(unsigned int line_number);

/* Other functions */
bool isnumber(void);
int exec_monty(FILE *);
void free_all(char *lineptr);
void (*get_address_func())(stack_t **, unsigned int);

#endif /* MONTY_H */
