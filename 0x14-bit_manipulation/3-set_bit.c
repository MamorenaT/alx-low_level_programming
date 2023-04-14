#include "main.h"

/**
 * set_bit - Bit values at given indexes are set to 1.
 * @n: A pointer to the number that needs to be changed.
 * @index: index of the bit.
 *
 * Return: if code is clear return 1, if code has errors return -1.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int m;

	if (index > 63)
		return (-1);

	m = 1 << index;
	*n = (*n | m);

	return (1);
}
