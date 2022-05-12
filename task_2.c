#include "monty.h"

/**
 * _pop - pop
 * @stack: stack
 * @line_number: line
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if (aux == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (aux->prev == NULL)
		*stack = NULL;
	else
	{
		aux->prev->next = NULL;
		*stack = aux->prev;
	}
}
