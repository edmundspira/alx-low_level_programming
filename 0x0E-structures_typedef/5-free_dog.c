#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - function that frees dog
 * @d: element
 *
 * Return: Nothing
 */

void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->owner);
		free(d->name);
		free(d);
	}
}
