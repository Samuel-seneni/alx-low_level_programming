#include "main.h"

/**
 * get_bit - get the value of a bit.
 * @index: index of the bit to get to 1
 * @n: the number to be checked of the value
 * Return: 1 for worked, -1 for error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int x;

	if (index > 63)
		return (-1);

	for (x = 0; x < index; x++)
		n = n >> 1;
	return ((n & 1));
}
