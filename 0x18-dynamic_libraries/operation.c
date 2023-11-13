#include <stdio.h>

int add(int x, int y);
int sub(int x, int y);
int mul(int x, int y);
int div(int x, int y);
int mod(int x, int y);

/**
 * add - adds two integers
 * @x: first integer
 * @y: second integer
 * Return: the sum
 */
int add(int x, int y)
{
	return (x + y);
}
/**
 * sub - substracts two integers
 * @x: first integers
 * @y: second integers
 * Return: the substract
 */
int sub(int x, int y)
{
	return (x - y);
}

/**
 * mul - multiplies two integers
 * @x: first integer
 * @y: second integers
 * Return: the multiple
 */
int mul(int x, int y)
{
	return (x * y);
}

/**
 * div - division of two integers
 * @x: first integers
 * @y: second integers
 * Return: division of two integers
 */
int div(int x, int y)
{
	return (x / y);
}

/**
 * mod - find the modulus of two integers
 * @x: first integers
 * @y: second integers
 * Return: the modulus
 */
int mod(int x, int y)
{
	return (x % y);
}
