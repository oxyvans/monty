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
//-----------------------reading--------------------------
	
	fclose(fp);
	return(0);
}
