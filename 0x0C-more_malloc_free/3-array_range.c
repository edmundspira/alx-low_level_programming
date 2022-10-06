#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers.
 * @min: minimum
 * @max: maximum
 *
 * Return: integer value
 */

int *array_range(int min, int max)
{
	int *a, i = 0;

	if (min > max)
		return (NULL);

	while (min <= max)
	{
		a[i] = min;
		i++;
		min++;
	}

	return (a);
}
