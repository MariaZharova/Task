/*
* This file is Binary_tree.h
* Binary Search Tree (BST) header
* Author Maria Zharova <MZharovaNN@yandex.ru>
* Created 01.12.2019
*/

#pragma once

#define FALSE 0
#define TRUE 1

typedef struct _TREE_NODE *PTREE_NODE;

typedef struct _TREE_NODE
{
	int value;
	PTREE_NODE left, right;
} TREE_NODE;

/*
 * Create BST
 * Arguments:
 *     none
 * Returns pointer to the created tree
 */
PTREE_NODE create_tree(void);

/*
 * Destroy BST
 * Arguments:
 *     tree - pointer to the tree
 * Returns none
 */
void destroy_tree(PTREE_NODE tree);

/*
 * Insert new element to the BST
 * Arguments:
 *     tree - pointer to the tree
 *	   value  - value of added element
 * Returns pointer to the inserted element
 */
PTREE_NODE insert_element(PTREE_NODE tree, int value);

/*
 * Delete element from the BST
 * Arguments:
 *     tree - pointer to the tree
 *	   key  - value of map key
 * Returns none
 */
void delete_element(PTREE_NODE tree, int value);

/*
 * Print the BST
 * Arguments:
 *     tree - pointer to the tree
 * Returns none
 */
void print_tree(PTREE_NODE tree);

/*
 * Find element in the BST
 * Arguments:
 *     tree - pointer to the tree
 *	   value  - value of finding element
 * Returns pointer to the founded element
 */
PTREE_NODE find_node(PTREE_NODE tree, int value);


