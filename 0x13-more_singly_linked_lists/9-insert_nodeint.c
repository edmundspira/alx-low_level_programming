#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - function
 * @head: double pointer to first node of list
 * @idx: index where new node should be added
 * @n: new node to insert
 *
 * Description: function to insert a new node at a given position
 * Return: the address of the new node, or null if fail
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *iter;
	unsigned int count = 1;

	if (head)
	{
		new_node = malloc(sizeof(listint_t));
		if (new_node == NULL)
			return (NULL);

		new_node->n = n;
		if (idx > 0)
		{
			iter = *head;
			while (iter)
			{
				if (count == idx)
				{
					new_node->next = iter->next;
					iter->next = new_node;
					return (new_node);
				}
				iter = iter->next;
				count++;
			}
			if (idx > count)
				return (NULL);
		}
		else
		{
			new_node->next = *head;
			*head = new_node;
		}
		return (new_node);
	}
	return (NULL);
}
