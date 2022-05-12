#include "monty.h"

/**
 * _swap - swaps
 * @stack: stack
 * @line_number: stack
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int i = 0;

	if (aux == NULL || aux->prev == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	i = aux->prev->n;
	aux->prev->n = aux->n;
	aux->n = i;
}
