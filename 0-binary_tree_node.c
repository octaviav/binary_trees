#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - creates a binary tree node.
 * @parent: Pointer to the parent node of the node to create.
 * @value: value to be stored in the new node.
 * Return: if memory allocation fails - NULL.
 * 	Otherwise - A pointer to the newly created node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->parent = parent;
	new->n = value;
	new->right = NULL;
	new->left = NULL;

	return (new);
}
