#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: Pointer to the node to measure depth.
 *
 * Return: Depth
 *	0 - if the tree is NULL 
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
i	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
