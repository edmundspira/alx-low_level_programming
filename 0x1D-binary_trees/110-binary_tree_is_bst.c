#include "binary_trees.h"
#include <limits.h>

/**
 * valid_search_tree - check validity of binary search tree
 * @tree: pointer to the tree to be checked
 * @min: minimum value
 * @max: maximum value
 * Return: 1 if tree is Binary Search Tree, 0 if not
 */

int valid_search_tree(const binary_tree_t *tree, int min, int max)
{
	size_t left_min, right_max;

	if (!tree)
		return (1);
	if (tree->n < min)
		return (0);
	if (tree->n > max)
		return (0);
	left_min = valid_search_tree(tree->left, min, tree->n - 1);
	right_max = valid_search_tree(tree->right, tree->n + 1, max);
	return (left_min && right_max);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if binary tree is valid Binary Search Tree, 0 if not
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (valid_search_tree(tree, INT_MIN, INT_MAX));
}
