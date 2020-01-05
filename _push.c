#include "monty.h"

void _push(stack_t **stack, unsigned int line_number)
{
  stack_t *tmp, *newNode;

  newNode = malloc(sizeof(stack_t));
  if (newNode == NULL)
  {
    fprintf(stderr, "Error: malloc failed\n");
    exit(EXIT_FAILURE);
  }

  if (opCodeVal == NULL && !isDigit())
  {
    fprintf(stderr, "L%u: usage: push integer\n", line_number);
    free(newNode);
    exit(EXIT_FAILURE);
  }

  //load node
  newNode->next = *stack;
  newNode->prev = NULL;
  newNode->n = atoi(opCodeVal);

  if (*stack)
    (*stack)->prev = newNode;
  *stack = newNode;

  return;
}
