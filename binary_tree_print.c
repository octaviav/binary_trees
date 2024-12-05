#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * print_tree - Recursivly formatstree into an array of strings.
 *
 * @node: Pointer to the tree node.
 * @level: Position to print.
 * @depth: Current depth of the node.
 * @output: Buffer
 *
 * Return: length of the tree
 */
static int print_tree(const binary_tree_t *node, int level, int depth, char **
		output)
{
	char c[6];
	int width, left, right, isleft, i;

	if (!node)
		return (0);

	isleft = (node->parent && node->parent->left == node);
	width = sprintf(c, "[%03d]", node->n);

	left = print_tree(node->left, level, depth + 1, output);
	right = print_tree(node->right, level + left + width, depth + 1, output);

	for (i = 0; i < left + width; i++)
		output[depth][level + left + i] = c[i];

	if (depth && isleft)
	{
		for (i = 0; i < width + right; i++)
			output[depth - 1][level + width / 2 + i] = '-';
		output[depth - 1][level + right + width / 2] = '+';
	}

	return (left + width + right);
}

/**
 * height_t - Determines the height of a binary tree
 *
 * @node: Pointer to the root.
 *
 * Return: height og the tree.
 */
static size_t height_t(const binary_tree_t *node)
{
	size_t height_l, height_r;

	if (!node)
		return (0);
	height_l = node->left ? 1 + height_t(node->left) : 0;
	height_r = node->right ? 1 + height_t(node->right) : 0;

	return (height_l > height_r ? height_l : height_r);
}

/**
 * print_binary_tree - Prints a visual representation of a binary tree
 *
 * @root: Pointer to the root node
 */
void print_binary_tree(const binary_tree_t *root)
{
	char **output;
	size_t height, n, j;

	if (!root)
		return;

	height = height_t(root);

	output = malloc(sizeof(*output) * (height + 1));
	if (!output)
		return;

	for (n = 0; n < height + 1; n++)
	{
		output[n] = malloc(sizeof(**output) * 255);
		if (!output[n])
			return;
		memset(output[n], ' ', 255);
	}

	print_tree(root, 0, 0, output);

	for (n = 0; n < height + 1; n++)
	{
		for (j = 254; j > 1; --j)
		{
			if (output[n][j] != ' ')
				break;
			output[n][j] = '\0';
		}
		printf("%s\n", output[n]);
		free(output[n]);
	}
	free(output);
}
