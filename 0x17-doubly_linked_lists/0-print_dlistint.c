#include "lists.h"

/**
 * print_dlistint - prints all elements of dlistint_t list
 * @h: head of the list
 * Reurn: the nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	int c;
	c = 0;

	if (h == NULL)
		return (c);
	while (h->prev != NULL)
		h = h->prev;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		c++;
		h = h->next;
	}
	return (c);
}
