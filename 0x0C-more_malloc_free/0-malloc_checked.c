#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * malloc_checked - Allocate memory
 *
 * @b: allocated size
 *
 * Return: pointer
 */

void *malloc_checked(unsigned int b)
{
	char *r;

	r = malloc(b);

	if (r == NULL)
	exit(98);
	return (r);
}
