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

	R_File(fp);

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
	int linenum;
	char *buf = NULL;
	size_t size = 0;
	stack_t *stack = NULL;

	for (linenum = 1; getline(&buff, &size, fp) != -1; ++linenum)
	{
		if (search(buf, linenum, stack) == 1)
		{
			free(buf);
			free_s(stack); // implementar 
			exit(EXIT_FAILURE);
		}
	}
	free(buf);
	free_s(stack); // implementar
	return (0);
}
