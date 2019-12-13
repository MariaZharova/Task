/*
* This file is Binary_tree.c
* Binary Search Tree (BTS) implementation
* Author Maria Zharova <MZharovaNN@yandex.ru>
* Created 11.11.2019
* (c) MIPT 2019
*/

#include "common.h"

PTREE_NODE create_elem(void)
{
	PTREE_NODE root;
	root = malloc(sizeof(TREE_NODE));
	if (NULL == root)
	{
		printf("create_elem: Error, out of memory:(\n");
		return ERROR_OUT_OF_MEMORY;
	}
	root->value = 0;
	root->left = NULL;
	root->right = NULL;

	return root;
}

void destroy_tree(PTREE_NODE tree)
{
	if (NULL == tree)
	{
		return;
	}

	destroy_tree(tree->left);
	destroy_tree(tree->right);
	free(tree);
}

PTREE_NODE insert_elem(PTREE_NODE tree, int key)
{
	if (NULL == tree)
	{
		tree = create_elem();
		tree->value = key;
		return tree;
	}	
	if (tree->value == key)
	{
		printf("insert_elem: This element already exists.\n");
		return ERROR_INSERT;
	}
	if (tree->value > key)
	{
		tree->left = insert_elem(tree->left, key);
	}
	else
	{
		tree->right = insert_elem(tree->right, key);
	}

	return tree;
}

void delete_elem(PTREE_NODE root, int key)
{
	PTREE_NODE curr = find_node(root, key);
	PTREE_NODE parent = NULL;
	if (NULL == curr)
	{
		printf("delete_elem: Error, this element was not founded\n");
		return;
	}

	if (NULL == curr->left)
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
	PTREE_NODE replace = curr->left;
	while (NULL != replace->right)
	{
		replace = replace->right;
	}
	int replaced_value = replace->value;
	delete_elem(replace, replaced_value);
	curr->value = replaced_value;
}


void wfs(PTREE_NODE tree)
{
	PTREE_NODE p;
	PQUEUE q = create_queue();
	queue_push(q, tree);
	while (NULL != q->head)
	{
		p = q->head->ptr;
		queue_pop(q);
		printf("%d ", p->value);

		if (p->left != NULL)
		{
			queue_push(q, p->left);
		}
		if (p->right != NULL)
		{
			queue_push(q, p->right);
		}
	}

}

void dfs(PTREE_NODE tree)
{
	if (NULL == tree)
	{
		return;
	}
	printf("%d\n", tree->value);
	dfs(tree->left);
	dfs(tree->right);
}


void print_tree(PTREE_NODE tree, int level)
{
	if (NULL == tree)
	{
		return;
	}
	print_tree(tree->left, level + 1);
	for (int i = 0; i < level; i++)
	{
		printf("   ");
	}
	printf("%d\n", tree->value);
	print_tree(tree->right, level + 1);
}

PTREE_NODE find_node(PTREE_NODE root, int key)
{
	PTREE_NODE curr = root;
	while (NULL != curr && curr->value != key)
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
	if (NULL == curr)
	{
		printf("find_node: Element was not founded.\n");
	}
	else
	{
		printf("find_node: Element was founded.\n");
	}

	return curr;
}
