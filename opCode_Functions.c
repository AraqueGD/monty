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
instruction_t opFunc[] = {
{"push", _push},
{"pall", _pall},
{"pint", _pint},
};
int rows = (sizeof(opFunc) / sizeof(opFunc[0])) - 1;
for (int idx = 0; idx <= rows; idx++)
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
 */

int isDigit(void)
{
int flag = 0;

if (opCodeVal == NULL)
{
return (flag);
}
for (int i = 0; opCodeVal[i]; i++)
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
