#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - function
 * @head: double pointer to 1st node in list
 *
 * Description: Function to delete the first node(head) in list
 * Return: Head node's data
 */
int pop_listint(listint_t **head)
{
	listint_t *new_head;
	int n = 0;

	if (*head != NULL)
	{
		new_head = (*head)->next;
		n = (*head)->n;
		free(*head);
		*head = new_head;
	}

	return (n);
}
