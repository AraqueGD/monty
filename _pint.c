#include "monty.h"

/**
 * _pint - prints only the value at the top of the doubly linked list
 * @stack: reference to the head of doubly linked list
 * @line_number: reference to line number if there is an error
 * Return: no return
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't pint, stack empty\n");
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
