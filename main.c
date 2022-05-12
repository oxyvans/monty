#include "monty.h"

/**
 * main - main
 * @argc: int
 * @argv: arg
 * Return: int
 */

int main(int argc, char *argv[])
{
	FILE *fp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	read(fp);
	fclose(fp);
	return(0);
}

/**
 * read - reding file
 * @fp: file
 * Return: int
 */

int read(FILE *fp)
{
	unsigned int linenum;
	char *buf = NULL;
	size_t size = 0;
	stack_t *stack = NULL;

	for (linenum = 1; getline(&buf, &size, fp) != -1; ++linenum)
	{
		
		if (search(buf, linenum, &stack) == 1)
		{
			free(buf);
			free_s(stack);
			exit(EXIT_FAILURE);
		}
	}
	free(buf);
	free_s(stack);
	return (0);
}

/**
 * search - search funcion
 * @buf: line
 * @linenum: line
 * @stack: stack
 * Return: int
 */
int search(char *buf, unsigned int linenum, stack_t **stack)
{
	char *tok = NULL;

	instruction_t form[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};

	tok = strtok(buf, " \n\t\r");
	if (tok == NULL)
		return(0);	
	if (exe(tok, form, linenum, stack) == 1)
	{
		exit(EXIT_FAILURE);
	}
	return (0);
}

/**
 *is_number - checks if number
 *@data: input
 * Return: 0 if num
 */

int is_number(char *data)
{
	int i = 0;
	int flag = 0;

	if (data[i] == '-')
	{
		flag = 0;
		i++;
	}
	
	while (data[i] != '\0' && flag != 1)
	{

		if (data[i] >= '0' && data[i] <= '9')
			flag = 0;
		else
			flag = 1;
		i++;
	}
	return (flag);
}
