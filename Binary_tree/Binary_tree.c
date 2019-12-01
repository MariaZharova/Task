/*
* This file is Binary_tree.c
* Binary Search Tree (BTS) implementation
* Author Maria Zharova <MZharovaNN@yandex.ru>
* Created 11.11.2019
*/

#include <stdio.h>
#include <stdlib.h>
#include "Binary_tree.h"
#define ERROR_OUT_OF_MEMORY NULL
#define ERROR_INVALID_INPUT NULL
#define ERROR_INVALID_INPUT_INT -1

PTREE_NODE create_tree(void)
{
	PTREE_NODE Root;
	Root = malloc(sizeof(TREE_NODE));
	if (NULL == Root)
	{
		printf("Error, out of memory:(\n");
		return ERROR_OUT_OF_MEMORY;
	}
	Root->value = 0;
	Root->left = NULL;
	Root->right = NULL;

	return Root;
}

void destroy_tree(PTREE_NODE tree)
{
	if (NULL == tree)
	{
		printf("Error, out of memory:(\n");
		return;
	}
	if (tree->left)
	{
		destroy_tree(tree->left);
	}
	if (tree->right)
	{
		destroy_tree(tree->right);
	}
	free(tree);
	}
	printf("It's OK. The all list has been deleted.\n");
}

PTREE_NODE insert_element(PTREE_NODE tree, int value)
{

}

void delete_element(PTREE_NODE tree, int value)
{
	PTREE_NODE curr = tree;
	PTREE_NODE parent = NULL;
	while (curr && curr->value != value)
	{
		parent = curr;
		if (value < curr->value)
		{
			curr = curr->left;
		}
		else
		{
			curr = curr->right;
		}

		if (NULL == curr)
		{
			return;
		}

		if(NULL == curr->left)
		{
			if (parent->left == curr)
			{
				parent->left = curr->right;
			}

			if (parent->right == curr)
			{
				parent->right = curr->right;
			}
			free(curr);

			return;
		}

		if (NULL == curr->right)
		{
			if (parent->left == curr)
			{
				parent->left = curr->left;
			}
			if (parent->right == curr)
			{
				parent->right = curr->left;
			}
			free(curr);

			return;
		}
	}
}

void print_tree(PTREE_NODE tree)
{
	if (tree->left)
	{
        print_tree(tree->left);
	}
	printf("< %d\n", tree->left->value);
	if (tree->right)
	{
		print_tree(tree->right);
	}
	printf("< %d\n", tree->right->value);
}

PTREE_NODE find_node(PTREE_NODE tree, int key)
{
	PTREE_NODE curr = tree;
	while (curr && curr->value != key)
	{
		if (key < curr->value)
		{
			curr = curr->left;
		}
		else
		{
			curr = curr->right;
		}
	}

	return curr;
}
