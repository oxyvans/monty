#include "monty.h"

/**
 * _div - div
 * @stack: stack
 * @line_number: line
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if (aux == NULL || aux->prev == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (aux->n != 0)
		aux->prev->n = aux->prev->n / aux->n;
	else
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	_pop(stack, line_number);
}
