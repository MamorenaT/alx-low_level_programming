#include "main.h"

/**
 * clear_bit - At a given index, sets a bit to zero.
 * @n: A pointer to the number that needs to be changed.
 * @index: index of the bit.
 *
 * Return: 1 if the code is clear, -1 if the code has errors.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int m;

	if (index > 63)
		return (-1);

	m = 1 << index;

	if (*n & m)
		*n ^= m;

	return (1);
}
