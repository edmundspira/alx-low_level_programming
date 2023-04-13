#include "binary_trees.h"
/**
 * binary_tree_nodes - count number of nodes with at least 1 child in a tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: number of nodes with at least 1 child, 0 if tree is NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree || binary_tree_is_leaf(tree))
		return (0);
	return (binary_tree_nodes(tree->left) + 1 + binary_tree_nodes(tree->right));
}

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to node being checked
 * Return: 0 if node is not a leaf, 1 if node is
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node || node->right || node->left)
		return (0);
	return (1);
}
