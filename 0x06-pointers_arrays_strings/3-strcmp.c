#include "main.h"

/**
 * _strcmp - compares two strings
 *
 * @s1: first string
 *
 * @s2: second string.
 *
 * If str1 == str2, 0
 *
 * If str1 > str2, the positive difference of the first unmatched characters
 *
 * Return: 0 if s1 and s2 are equals, another number if not.
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
	s1++;
	s2++;
	}
	return (*s1 - *s2);
}
