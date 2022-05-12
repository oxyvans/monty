#include "monty.h"

/**
 * _pstr - pstr
 * @stack: stack
 * @line_number: line
 */

void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	(void)line_number;

	if (aux == NULL)
	{
		printf("\n");
		return;
	}

	while ((aux != NULL) && ((isascii(aux->n)) && (aux->n != 0)))
	{
		printf("%c", (char)(aux->n));
		aux = aux->prev;
	}
	printf("\n");
}
