#include "monty.h"

/**
 * _pchar - pchar
 * @stack: stack
 * @line_number: line
 */

void _pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (isascii((*stack)->n))
		printf("%c\n", (char)((*stack)->n));
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}
