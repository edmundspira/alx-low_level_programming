#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: the lowest common ancestor node of the two given nodes
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *place_holder;

	if (!first || !second || (!first->parent && !second->parent))
		return (NULL);

	while (first)
	{
		place_holder = (binary_tree_t *)second;
		while (place_holder)
		{
			if (place_holder->n == first->n)
				return (place_holder);
			place_holder = place_holder->parent;
		}
		first = first->parent;
	}
	return (NULL);
}
