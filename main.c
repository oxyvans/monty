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
 * R_File - reding file
 * @fp: file
 */

void R_File(FILE *fp)
{
	int linenum;
	char *p, buf[1024];

	for (linenum = 1; fgets(buf, sizeof(buf), fp) != NULL; ++linenum)
	{
	}
}
