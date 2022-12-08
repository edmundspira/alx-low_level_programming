#include "lists.h"

/**
 * add_dnodeint_end - adds a node to the end of a dlist
 * @head: head node
 * @n: number to add to new node
 * Return: address of the new node, on NULL on failure
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *walk;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*head != NULL)
	{
		walk = *head;
		while (walk->next != NULL)
		{
			walk = walk->next;
		}
		walk->next = new;
		new->prev = walk;
	}
	else
	{
		new->prev = NULL;
		*head = new;
	}
	return (new);
}
