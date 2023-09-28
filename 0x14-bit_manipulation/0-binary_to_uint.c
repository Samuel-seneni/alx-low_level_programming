#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - converts a binary number to decimal number
 * @b: a string of binary number to be converted
 * Return: converted number of 1 or 0
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int len;
	size_t x = 0;
	size_t y = 0;
	size_t sum = 0;
	size_t p = 1;
	int base = 2;

	if (b == NULL)
		return (0);

	for (len = 0; b[len] != '\0'; len++)
		;
	if (len == 1 && (b[0] == '0' || b[0] == '1'))
		return (b[0] - 48);

	for (x = 0; b[x] != '\0'; x++)
	{
		if (b[x] != '0' && b[x] != '1')
			return (0);
		for (y = len - 1; y > 0; y--)
		p = p * base;
		sum = sum + (p * (b[x] - 48));
		len--;
		p = 1;
	}
	return (sum);
}
