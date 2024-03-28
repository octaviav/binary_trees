#include "binary_trees.h"

/**
 * binary_tree_height - measures the heigh of a binary tree
 * @tree: pointer to the root nose of the tree to measure the height.
 *
 * Return: height of the binary tree.
 *	If tree is null - 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_h = 0, right_h = 0;

		left_h = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		right_h = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((left_h > right_h) ? left_h : right_h);
	}
	return (0);
}
