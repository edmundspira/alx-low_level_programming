#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts node as a left child of a node
 * @parent: parent to insert
 * @value: value to insert
 * Return: pointer to the new node, NULL on failure
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_child;

	if (!parent)
		return (NULL);
	new_child = binary_tree_node(parent, value);
	if (!new_child)
		return (NULL);
	new_child->left = parent->left;
	if (new_child->left)
		new_child->left->parent = new_child;
	parent->left = new_child;
	return (new_child);
}
