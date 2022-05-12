#include "monty.h"

/**
 * _add - add
 * @stack: stack
 * @line_number: line
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if (aux == NULL || aux->prev == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	aux->prev->n = aux->prev->n + aux->n;
	_pop(stack, line_number);
}
