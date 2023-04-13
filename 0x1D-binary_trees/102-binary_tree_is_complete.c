#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if complete, 0 if tree is NULL
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);

	size = binary_tree_size(tree);
	return (tree_check(tree, 0, size));
}

/**
 * tree_check - checks if a binary tree is complete
 * @tree: pointer to the root node of a tree to be checked for complete
 * @index: starting index
 * @size: size of binary tree
 * Return: 1 if tree if complete, 0 if incomplete
 */

int tree_check(const binary_tree_t *tree, size_t index, size_t size)
{
	size_t left, right;

	if (!tree)
		return (1);

	if (index >= size)
		return (0);
	left = tree_check(tree->left, 2 * index + 1, size);
	right = tree_check(tree->right, 2 * index + 2, size);
	return (left && right);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of a binary tree, 0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
