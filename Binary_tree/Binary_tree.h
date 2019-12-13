/*
* This file is Binary_tree.h
* Binary Search Tree (BST) header
* Author Maria Zharova <MZharovaNN@yandex.ru>
* Created 01.12.2019
*/

#pragma once

typedef struct _TREE_NODE *PTREE_NODE;

typedef struct _TREE_NODE
{
	int value;
	PTREE_NODE left, right;
} TREE_NODE;

/*
 * Create new element (or new tree)
 * Arguments:
 *     none
 * Returns pointer to the created tree
 */
PTREE_NODE create_elem(void);

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
 *	   key  - value of added element
 * Returns pointer to the inserted element
 */
PTREE_NODE insert_elem(PTREE_NODE tree, int key); 

/*
 * Delete element from the BST
 * Arguments:
 *     tree - pointer to the tree
 *	   key  - value of map key
 * Returns none
 */
void delete_elem(PTREE_NODE tree, int key); 

/*
 * Width first search
 * Arguments:
 *     tree - pointer to the tree
 * Returns none
 */
void wfs(PTREE_NODE tree);

/*
 * Depth first search
 * Arguments:
 *     tree - pointer to the tree
 * Returns none
 */
void dfs(PTREE_NODE tree);

/*
 * Print the BST
 * Arguments:
 *     tree - pointer to the tree
 *     level - number of spaces
 * Returns none
 */
void print_tree(PTREE_NODE tree, int level);

/*
 * Find element in the BST
 * Arguments:
 *     tree - pointer to the tree
 *	   key  - value of finding element
 * Returns pointer to the founded element
 */
PTREE_NODE find_node(PTREE_NODE tree, int key);




