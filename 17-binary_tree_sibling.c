#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node to a tree.
 * @node: Pointer to the node to find the sibling of.
 *
 * Return:Pointer to the sibling
 * 	NULL - if the node is NULL or there are no siblings
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
