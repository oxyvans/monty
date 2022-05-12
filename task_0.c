#include "monty.h"

/**
 * _push - push
 * @stack: stack
 * @line_number: line
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *node, *aux = *stack;
	(void)line_number;

	node = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_s(stack);
		exit(EXIT_FAILURE);
	}

	node->n = value;

	if (aux == NULL)
	{
		node->prev = NULL;
		node->next = NULL;
		*stack = node;
	}
	else
	{
		node->next = NULL;
		node->prev = aux;
		aux->next = node;
		*stack = node;
	}
}

/**
 * _pall - pall
 * @stack: stack
 * @line_number: line
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	(void)line_number;

	while(aux)
	{
		printf("%d\n", aux->n);
		aux = aux->prev;
	}
}

/**
 * free_s - pall
 * @stack: stack
 */

void free_s(stack_t *stack)
{
	stack_t *save = stack;

	if (stack == NULL)
	{
		return;
	}
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	while (stack != NULL)
	{
		save = stack;
		stack = stack->prev;
		free(save);
	}
}
