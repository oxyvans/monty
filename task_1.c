#include "monty.h"

/**
 *_pint- prints
 *@stack: stack
 *@line_number: line number
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		frStack(stack);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->n);
}
