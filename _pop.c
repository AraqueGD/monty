#include "monty.h"

/**
 * _pop - removes only the top element of the doubly linked list
 * @stack: reference to the head of doubly linked list
 * @line_number: reference to line number if there is an error
 * Return: no return
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}
