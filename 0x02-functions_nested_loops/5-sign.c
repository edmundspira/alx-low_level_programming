#include "main.h"

/**
 * print_sign - prints the sign of a number
 *
 * @n: is the int that will use for the argument of the function
 *
 * Return: 0
 */

int print_sign(int n)
{
	if (n > 0)
	{
		_putchar("+");
		return (1);

		if (n < 0)
		{
			_putchar("-");
			return (-1);
		}

	
		else
			return (0);
	}
}
