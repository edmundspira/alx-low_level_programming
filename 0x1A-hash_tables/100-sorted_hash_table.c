#include "hash_tables.h"
#include <ctype.h>

/**
 * shash_table_create - creates a new shash_table_t
 *
 * @size: size of shash_table_t
 * Return: Returns NULL on failure, or pointer to new shash_table_t
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_table;

	if (size == 0)
		return (NULL);
	new_table = malloc(sizeof(shash_table_t));
	if (new_table == NULL)
		return (NULL);
	new_table->size = size;
	new_table->array = calloc(size, sizeof(shash_node_t *));
	if (new_table->array == NULL)
		return (NULL);
	return (new_table);

}

/**
 * table_size - returns the size of a shash_table_t
 *
 * @ht: ht to get size of
 * Return: returns total size
 */
int table_size(shash_table_t *ht)
{
	unsigned int i;
	int total;

	for (i = 0, total = 0; i < ht->size; i++)
		if (ht->array[i] != NULL)
			total++;
	return (total);
}

/**
 * table_set - sets a value to a key in a shash_table_t
 *
 * @ht: shash_table_t
 * @key: key for bucket
 * @value: value for bucket
 * Return: Returns 1 on success, 0 otherwise
 */
shash_node_t *table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int hsh;
	shash_node_t *node, *walk;

	if (!ht || !key || !value || strlen(key) == 0)
		return (NULL);
	hsh = key_index((unsigned char *)key, ht->size);
	if (ht->array[hsh])
	{
		walk = ht->array[hsh];
		while (walk && strcmp(walk->key, key) != 0)
			walk = walk->next;
		if (walk && strcmp(walk->key, key) == 0)
		{
			free(walk->value);
			walk->value = strdup(value);
			return (walk);
		}
	}
	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
	{
		return (NULL);
	}
	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (NULL);
	}
	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (NULL);
	}
	node->next = ht->array[hsh];
	ht->array[hsh] = node;
	return (node);
}

/**
 * shash_table_set - sets a value in a hash table, then sets it in an order ll
 *
 * @key: key in table
 * @value: value in table
 * Return: Returns 0 on failure, 1 on success
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int hsh;
	shash_node_t *node, *walk;

	hsh = key_index((unsigned char *)key, ht->size);
	if (ht->array[hsh] != NULL)
		if (strcmp((ht->array[hsh])->value, value) == 0)
			return (1);
	node = table_set(ht, key, value);
	if (node == NULL)
		return (0);
	node->snext = NULL; node->sprev = NULL;
	if (table_size(ht) == 1)
	{
		ht->shead = node; ht->stail = node;
		return (1);
	}
	walk = ht->shead;
	if (key[0] < walk->key[0])
	{
		node->snext = ht->shead;
		(ht->shead)->sprev = node;
		ht->shead = node;
		return (1);
	}
	walk = sort(walk, key, node);
	if (walk == NULL)
		return (1);
	node->snext = walk; node->sprev = walk->sprev;
	(walk->sprev)->snext = node; walk->sprev = node;
	return (1);
}

shash_node_t *sort(shash_node_t *walk, const char *key, shash_node_t *node)
{
	int x;

	x = 0;
	while (tolower(walk->key[x]) <= tolower(key[x]))
	{
		if (tolower(walk->key[x]) == tolower(key[x]))
		{
			x++;
			if (key[x] == '\0')
			{
				x = 0; walk = walk->snext;
			}
			if (walk->key[x] == '\0')
				break;
		}
		else
		{
			if (walk->snext == NULL)
			{
				walk->snext = node;
				node->sprev = walk;
				return (NULL);
			}
			walk = walk->snext;
			x = 0;
		}
	}
	return (walk);
}

/**
 * shash_table_get - returns a value associated with a key in a ht
 *
 * @ht: shash_table_t we're working with
 * @key: key to search for
 * Return: Returns pointer to value, or NULL on fail
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int hsh;
	shash_node_t *node;

	if (ht == NULL || key == NULL)
		return (NULL);
	hsh = key_index((const unsigned char *) key, ht->size);
	if (ht->array != NULL && ht->array[hsh] != NULL)
	{
		node = ht->array[hsh];
		while (strncmp(node->key, key, strlen(key)) != 0 && node)
		{
			node = node->next;
		}
		if (node && strncmp(node->key, key, strlen(key)) == 0)
			return (node->value);
	}
	return (NULL);
}

/**
 * shash_table_print - prints a shash_table_t out
 *
 * @ht: shash_table_t to print
 */
void shash_table_print(const shash_table_t *ht)
{
	unsigned int flag;
	shash_node_t *walk;

	flag = 0;
	if (ht == NULL)
		return;
	printf("{");
	if (ht->array == NULL)
	{
		printf("}\n");
		return;
	}
	walk = ht->shead;
	while (walk != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", walk->key, shash_table_get(ht, walk->key));
		flag = 1;
		walk = walk->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a shash_table_t out in reverse
 *
 * @ht: shash_table_t to print
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	unsigned int flag;
	shash_node_t *walk;

	flag = 0;
	if (ht == NULL)
		return;
	printf("{");
	if (ht->array == NULL)
	{
		printf("}\n");
		return;
	}
	walk = ht->shead;
	while (walk->snext != NULL)
		walk = walk->snext;
	while (walk != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", walk->key, shash_table_get(ht, walk->key));
		flag = 1;
		walk = walk->sprev;
	}
	printf("}\n");
}
