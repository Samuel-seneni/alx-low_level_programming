#include "lists.h"

/**
 * sum_dlistint -  returns the sum of all the data (n) of a dlistint_t linked list.
 * @head: double pointer to the head
 * Return: 0
 */
int sum_dlistint(dlistint_t *head)
{

	int sum = 0;
	dlistint_t *x;

	for (x = head; x != NULL; x = x->next)
	{
		sum += x->n;
	}
	return (sum);
}
