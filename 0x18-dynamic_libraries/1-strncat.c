#include "main.h"

/**
 * _strncat - concatenates bytes from string to another
 * @dest: string destination
 * @src: string source
 * @n: number of bytes to concanate
 * Return: a pointer of the string destination
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
