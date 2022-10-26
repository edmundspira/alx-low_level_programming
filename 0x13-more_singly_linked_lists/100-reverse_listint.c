#include <stdlib.h>
#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t list.
 * @head: A pointer to the address
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *next = NULL;

	if (head)
	{
		while (*head)
		{
			next = *head;
			*head = (*head)->next;
			next->next = prev;
			prev = next;
		}

		*head = prev;
		return (*head);
	}

	return (NULL);
}
