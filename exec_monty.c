/**
 * exec_monty - Execute interpreter monty code
 * @fileptr: Pointer to input monty file
 *
 * fileptr     - Pointer to input monty file
 * lineptr     - Pointer to buffer line read
 * len_buff    - The buffer size of lineptr
 * Stack       - Pointer to struct stack_t
 * func_ptr    - Pointer to the corresponding function
 * line_number - Working Line number from monty file
 *
 * Return: (EXIT_SUCCESS) or (EXIT_FAILURE)
 */
#include "monty.h"
#include <string.h>

int exec_monty(FILE *fileptr)
{
	char *lineptr = NULL;
	size_t len_buff = 0;
	stack_t *Stack = NULL;
	void (*func_ptr)(stack_t **, unsigned int);
	int line_number = 0;

	if (init_stack(&Stack) == EXIT_FAILURE)
	{
		free_all(lineptr);
		return (EXIT_FAILURE);
	}

	while ((getline(&lineptr, &len_buff, fileptr)) != -1)
	{
		line_number++;
		info.opc_code = strtok(lineptr, DELIMITERS);

		if (info.opc_code == NULL || strncmp(info.opc_code, "#", 1) == 0)
			continue;

		info.val_arg = strtok(NULL, DELIMITERS);

		func_ptr = get_address_func(line_number);
		if (func_ptr == NULL)
		{
			free_all(lineptr);
			free_stack(&Stack);
			return (EXIT_FAILURE);
		}

		func_ptr(&Stack, line_number);
	}

	return (EXIT_SUCCESS);
}

/**
 * get_address_func - Get address from a function monty interpreter
 * @line_number: Working line number from input monty file
 * Return: A pointer to function to execute
 */

void (*get_address_func(unsigned int line_number))(stack_t **top, unsigned int)
{
	instruction_t *ins_ptr;
	instruction_t func[] = {{"pop", _push},
							{"push", _push},
							{NULL, NULL}};

	ins_ptr = func;

	while (ins_ptr->opcode && strcmp(info.opc_code, ins_ptr->opcode))
		ins_ptr++;

	if (!ins_ptr->f)
	{
		error_unknown_instruction(line_number);
		return (ins_ptr->f);
	}

	return (ins_ptr->f);
}

/**
 * free_all - Free all variables and pointers
 * @lineptr: Pointer to buffer read by getline() function
 */
void free_all(char *lineptr)
{
	free(info.val_arg);
	free(info.opc_code);
	free(lineptr);
}
