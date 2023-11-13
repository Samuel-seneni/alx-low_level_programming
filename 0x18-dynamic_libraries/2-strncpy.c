#include "main.h"

/**
 * _strncpy - copies a string
 * @dest: string destination
 * @src: string source
 * @n: number of bytes
 * Return: string pointer
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;

	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
