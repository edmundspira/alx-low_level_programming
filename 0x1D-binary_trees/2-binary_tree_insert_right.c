#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts node as the right child of parent node
 * @parent: parent node to insert at
 * @value: value to insert
 * Return: new node, NULL on failure
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_child;

	if (!parent)
		return (NULL);
	new_child = binary_tree_node(parent, value);
	if (!new_child)
		return (NULL);
	new_child->right = parent->right;
	if (new_child->right)
		new_child->right->parent = new_child;
	parent->right = new_child;
	return (new_child);
}
