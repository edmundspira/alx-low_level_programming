#include "binary_trees.h"

/**
 * binary_tree_node - create new binary tree node
 * @parent: parent for new node
 * @value: value for new node
 * Return: pointer to new node, NULL on malloc failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	newnode = malloc(sizeof(binary_tree_t));
	if (newnode == NULL)
		return (NULL);
	newnode->n = value;
	newnode->parent = parent;
	newnode->right = NULL;
	newnode->left = NULL;
	return (newnode);
}
