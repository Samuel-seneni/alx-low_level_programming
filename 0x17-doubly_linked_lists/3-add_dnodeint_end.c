#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at end of a dlistint_t list
 * @head: list head
 * @n: element value
 * Return: new element
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *node;

	node = malloc(sizeof(dlistint_t));

	if (node == NULL)
		return (NULL);

	node->n = n;
	node->next = NULL;

	if (*head == NULL)
	{
		node->prev = NULL;
		*head = node;
		return (node);
	}

	while ((*head)->next != NULL)
		*head = (*head)->next;

	(*head)->next = node;
	node->prev = *head;

	return (node);
}
