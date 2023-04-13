#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *left, *right;

	if (!tree)
		return (0);
	left = tree->left;
	right = tree->right;
	if (binary_tree_height(left) != binary_tree_height(right))
		return (0);

	if (!left && !right)
		return (1);

	if (left && right)
	{
		if (binary_tree_is_perfect(left) && binary_tree_is_perfect(right))
			return (1);
	}

	return (0);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of tree, or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (tree == NULL)
		return (0);
	else if (tree->left || tree->right)
	{
		left = binary_tree_height(tree->left);
		right = binary_tree_height(tree->right);
		if (left >= right)
			return (left + 1);
		return (right + 1);
	}
	else
		return (0);
}
