#include "lists.h"

/**
 * free_dlistint - frees a dlist
 * @head: head of dlist
 * Return: void
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *walk;

	while (head != NULL)
	{
		walk = head;
		head = head->next;
		free(walk);
	}
}
