#include "monty.h"

void opCode_Functions(stack_t **stack, char *instr, ssize_t line_number)
{
  int idx;
  instruction_t opFunc[] = {
      {"push", _push},
      {"pall", _pall},
      {NULL, NULL}};

  for (idx = 0; opFunc[idx].opcode; idx++)
  {
    if (strcmp(opFunc[idx].opcode, instr) == 0)
    {
      opFunc[idx].f(stack, line_number);
      return;
    }
  }

  if (opFunc[idx].opcode == NULL)
  {
    fprintf(stderr, "L%lu: unknown instruction %s\n", line_number, instr);
    exit(EXIT_FAILURE);
  }

  return;
}

// Verify if opCode's argument is numeric
_Bool isDigit()
{
  _Bool isDigit = 1;
  for (int i = 0; *opCodeVal; i++)
  {
    if (opCodeVal[1] >= 48 && opCodeVal[i] <= 57)
      continue;
    else
    {
      isDigit = 0;
      break;
    }
  }
  return (isDigit);
}
