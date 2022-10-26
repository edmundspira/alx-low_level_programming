#include <stdlib.h>
#include "lists.h"

/**
 * sum_listint - function
 * @head: pointer to first node of list
 *
 * Description: func to return the sum of all data(n) in listint_t.
 * Return: sum of all data.
 */
int sum_listint(listint_t *head)
{
	int amount = 0;

	if (head)
	{
		while (head)
		{
			amount += head->n;
			head = head->next;
		}
	}

	return (amount);
}
