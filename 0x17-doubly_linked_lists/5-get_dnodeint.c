#include "lists.h"

/**
 * get_dnodeint_at_index - gets a the value of a dnode_int at the index
 * @head: head of dlist
 * @index: index of node to grab
 * Return: address of the node
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;
	dlistint_t *node;

	if (head == NULL)
		return (NULL);

	i = 0;
	node = head;
	while (i != index)
	{
		node = node->next;
		i++;
		if (node == NULL)
			return (NULL);
	}
	return (node);
}
