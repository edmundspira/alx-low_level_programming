#include <stdlib.h>
#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to flip
 * from one number to another
 * @n: base number
 * @m: number to transform to
 * Return: Number of bit transformations needed
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int mask = 0, count = 0;

	mask = n ^ m;
	while (mask)
	{
		if (mask & 1)
			count++;
		mask >>= 1;
	}

	return (mask);
}

