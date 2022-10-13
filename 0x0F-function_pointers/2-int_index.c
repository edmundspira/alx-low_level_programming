#include "function_pointers.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * int_index - fills memory with a constant byte
 * @array: is the array
 * @size: is the size of the array
 * @cmp: is funtion pointer
 *
 * Return: Nothing
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (size > 0)
	{
		if (array != NULL && cmp != NULL)
		{
			while (i < size)
			{
				if (cmp(array[i]))
					return (i);

				i++;
			}
		}
	}
	return (-1);
}
