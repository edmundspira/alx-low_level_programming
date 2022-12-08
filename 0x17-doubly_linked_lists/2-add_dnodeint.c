#include "lists.h"
#include <stdlib.h>
/**
 * add_dnodeint - adds a node to a doubly linked list
 * @head: head of dlist
 * @n: number to put into new node
 * Return: address of the new element, or NULL on failure
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	if (*head)
		(*head)->prev = new;

	*head = new;
	return (new);
}
