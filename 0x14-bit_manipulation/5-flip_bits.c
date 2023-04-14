#include "main.h"

/**
 * flip_bits - returns how many bits it would need to flip between two numbers
 * @n: number one.
 * @m: number two.
 *
 * Return:total amount of bits.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int nbits;

	for (nbits = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((n & 1) != (m & 1))
			nbits++;
	}

	return (nbits);
}
