#include "monty.h"

void _pall(stack_t **stack, unsigned int line_number)
{
  stack_t *current;
  current = *stack;
  while (current != NULL)
  {
    printf("%d\n", current->n);
    current = current->next;
  }
}
