#include "binary_trees.h"

/**
 * binary_tree_sibling - find the sibling of a node.
 * @node: pointer tot he node to find the sibling.
 *
 * Return: pointer to the sibling node.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
