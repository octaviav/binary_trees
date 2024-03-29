#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of the binary tree
 * @tree: pointer to the root node of the tree to measure the heigh
 *
 * Return: height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_h, right_h;

		left_h = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		right_h = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((left_h > right_h) ? left_h : right_h);
	}
	return (0);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}
