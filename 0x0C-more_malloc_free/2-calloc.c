#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory
 *
 * @nmemb: number of elements.
 *
 * @size: size of bytes.
 *
 * Return: pointer
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *z;
	int a = 0, b = 0;

	if (nmemb == 0 || size == 0)
	return (NULL);

	b = nmemb * size;
	z = malloc(b);

	if (z == NULL)
	return (NULL);

	while (a < b)
	{
	z[a] = 0;
	a++;
	}
	return (z);
}
