#include "main.h"
#include <stdio.h>

/**
 * clear_bit - sets the value of bit.
 * @index: index of the bit to clear
 * @n: pointer to the num
 * Return: 1 for worked or -1 for error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int x;

	x = 1;
	x = x << index;
	if (index > 63 || n == NULL)
		return (-1);

	if (((*n >> index) & 1) == 1)
		*n = x ^ *n;
	return (1);
}

