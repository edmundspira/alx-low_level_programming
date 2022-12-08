#include "lists.h"

/**
 * dlistint_len - returns the length of a dlistint list
 * @h: head of dlistint
 * Return: Returns number of elements in doubly linked list
 */
size_t dlistint_len(const dlistint_t *h)
{
	int i;

	i = 0;
	while (h != NULL)
	{
		h = h->next;
		i++;
	}
	return (i);
}
