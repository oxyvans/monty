#include "morty.c"

/**
 * exe - exe funcion
 * @tok: line
 * @op_code: funcions
 * @linenum: line
 * @stack: stack
 * Return: int
 */

int exe(char *tok, instruction_t *form, int linenum, stack_t **stack)
{
	char *val = NULL;
	int i = 1;
	int value;

	while(form[i].opcode != NULL)
	{
		if (strcmp(form[0].opcode, tok) == 0)
		{
			val = strtok(NULL, " \n\t\r");
			if (val == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", linenum);
				exit(EXIT_FAILURE);

			}
			value = atoi(val);
			form[0].f(value, stack);
		}
		if (strcmp(form[i].opcode, tok) == 0)
		{
			form[i].f(stack, linenum);
		}

		i++;
	}
	if (form[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, tok);
		exit(EXIT_FAILURE);
	}
	return (0);
}
