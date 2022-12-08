#include "lists.h"

/**
 * sum_dlistint - returns the sum of all dlistint nodes
 * @head: head of dlist
 * Return: number of nodes in dlist
 */
int sum_dlistint(dlistint_t *head)
{
	int i;

	i = 0;
	while (head != NULL)
	{
		i += head->n;
		head = head->next;
	}
	return (i);
}
