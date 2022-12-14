#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * main - print the name of this function
 * @argc: has the length of the arguments
 * @argv: has the arguments
 * Return: 0 (Success)
 */

int main(int argc, char **argv)
{
	int (*oprt)(int, int);

	if (argc > 4)
	{
		printf("Error\n");
		exit(98);
	}

	oprt = get_op_func(argv[2]);

	if (!oprt)
	{
		printf("Error\n");
		exit(99);
	}

	printf("%d", oprt(atoi(argv[1]), atoi(argv[3])));
	return (0);
}
