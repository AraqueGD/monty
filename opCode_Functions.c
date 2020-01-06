#include "monty.h"

/**
 * opCode_Functions - function add nodes in Stack
 * @top: the opcode
 * @line_number: function to handle the opcode
 * @instr: Instruction
 */

void opCode_Functions(stack_t **top, char *instr, unsigned int line_number)
{
	int flag = 1;
	int idx;
	instruction_t opFunc[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
	};
	int rows = (sizeof(opFunc) / sizeof(opFunc[0])) - 1;

	for (idx = 0; idx <= rows; idx++)
	{
		if (strcmp(opFunc[idx].opcode, instr) == 0)
		{
			opFunc[idx].f(top, line_number);
			flag = 0;
			break;
		}
	}
	if (flag == 1)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, instr);
		exit(EXIT_FAILURE);
	}
}

/**
 * isDigit - Valid Digits
 * return: Flag
 * @void: Nothing
 */

int isDigit(void)
{
	int flag = 0;
	int i;

	if (opCodeVal == NULL)
	{
		return (flag);
	}
	for (i = 0; opCodeVal[i]; i++)
	{
		if (opCodeVal[i] >= 48 && opCodeVal[i] <= 57)
			flag = 1;
		else
		{
			flag = 0;
			break;
		}
	}
	return (flag);
}
