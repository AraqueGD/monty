#include "monty.h"

//Initialize Stack
stack_t *initStack(FILE *fd)
{
  stack_t *sp = malloc(sizeof(stack_t));
  if (sp == NULL)
  {
    fclose(fd);
    fprintf(stderr, "Error: malloc failed\n");
    exit(EXIT_FAILURE);
  }

  sp->n = 0;
  sp->next = NULL;
  sp->prev = NULL;
  return (sp);
}
