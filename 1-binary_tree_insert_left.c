#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as a left-child of tree.
 * @parent: A pointer to insert the left child in
 * @value: Value of the new node.
 *
 * Return: Pointer to the new node
 *         NULL  if an error occurs or parent is NULL
 *
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	parent->left = new_node;

	return (new_node);
}
