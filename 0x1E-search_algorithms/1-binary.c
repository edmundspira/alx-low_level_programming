#include "search_algos.h"

/**
 * print_array - prints array each time it changes
 * @array: array of integers.
 * @left: beginning of new array.
 * @right: end of new array.
 */
void print_array(int array[], size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%i", array[i]);
		if (i < right)
		{
			printf(", ");
		}
		else
		{
			printf("\n");
		}
	}
}

/**
 * binary_search - uses binary search to find value in array
 * @array: array to search
 * @size: size of array
 * @value: value to search for
 * Return: index of value, or -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
	int first, middle, last;

	first = 0;
	last = (int) size - 1;
	middle = (first + last) / 2;

	if (array == NULL)
		return (-1);

	while (first <= last)
	{
		print_array(array, first, last);
		if (array[middle] < value)
			first = middle + 1;
		else
			last = middle - 1;
		if (array[middle] == value)
			return (middle);
		middle = (first + last) / 2;
	}
	return (-1);
}
