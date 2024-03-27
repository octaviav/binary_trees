#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if given node is a root.
 * @node: pointer to the node to check.
 * Return: If successful - 1.
 *	Otherwise - 0.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return (node != NULL && node->parent == NULL);
}
