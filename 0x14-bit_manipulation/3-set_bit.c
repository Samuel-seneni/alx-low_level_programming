#include "main.h"

/**
 * set_bit - get the value of a bit.
 * @index: index of the bit to get to 1
 * @n: the number to be checked of the value
 * Return: 1 for worked, -1 for error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int x;

	if (index > 63)
		return (-1);
	x = 1;
	x = x << index;
	*n = ((*n) | x);
	return (1);
}
