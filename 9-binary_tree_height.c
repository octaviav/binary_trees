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
	size_t left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = binary_tree_height(tree->left);
	right_h = binary_tree_height(tree->right);

	return (left_h > right_h ? left_h : right_h);
}
