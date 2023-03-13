#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - prints sum of arguments for positive numbers
 *
 * @argc: argument count
 *
 * @argv: argument vector
 *
 * Return: Always 0 Success
 */

int main(int argc, char *argv[])
{
	int i;
	unsigned int s, sum = 0;
	char *r;

	if (argc > 1)
	{
	for (i = 1; i < argc; i++)
	{
	r = argv[i];

	for (s = 0; s < strlen(r); s++)
	{
	if (r[s] < 48 || r[s] > 57)
	{
	printf("Error\n");
	return (1);
	}
	}
	sum += atoi(r);
	r++;
	}
	printf("%d\n", sum);
	}
	else
	{
	printf("0\n");
	}
	return (0);
}
