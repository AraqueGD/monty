#include "monty.h"

/**
 * _push - Pushes a value to a stack_t linked list.
 * @top: A pointer to the top node of the stack.
 * @line_number: The current working line number of the monty file
 */

void _push(stack_t **top, unsigned int line_number)
{
	stack_t *np = (stack_t *)malloc(sizeof(stack_t));

	if (np == NULL)
	{
		error_malloc();
	}

	np->n = atoi(info.val_arg);
	np->next = *top;
	np->prev = NULL;

	if (*top)
		(*top)->prev = np;
	*top = np;
	(void)line_number;
}
