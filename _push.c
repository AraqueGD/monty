#include "monty.h"

/**
 * _push - function add nodes in Stack
 * @stack: the opcode
 * @line_number: function to handle the opcode
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (!isDigit())
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(newNode);
		exit(EXIT_FAILURE);
	}

	newNode->next = *stack;
	newNode->prev = NULL;
	newNode->n = atoi(opCodeVal);

	if (*stack)
		(*stack)->prev = newNode;
	*stack = newNode;
}
