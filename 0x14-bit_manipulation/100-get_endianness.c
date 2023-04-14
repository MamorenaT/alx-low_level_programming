#include "main.h"

/**
 * get_endianness - A check is made to see if endian is big or small.
 *
 * Return: 0 if endian is big, 1 if endian is little
 */
int get_endianness(void)
{
	unsigned int x;
	char *c;

	x = 1;
	c = (char *) &x;

	return ((int)*c);
}
