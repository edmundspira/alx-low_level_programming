#include "search_algos.h"

/**
 * linear_search - searches for a value in array using the Linear search algo
 * @array:a pointer to the first element of the array to search in
 * @size:is the number of elements in array
 * @value:the first index where value is located
 * Return: first index where value is located, or -1 on failure
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;
	int tmp;

	if (array != NULL)
	{
		for (i = 0; i < size; i++)
		{
			tmp = array[i];
			printf("Value checked array[%lu] = [%d]\n", i, tmp);
			if (tmp == value)
				return (i);
		}
	}
	return (-1);
}
