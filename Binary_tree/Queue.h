/*
 * File:  queue.h
 * Brief: Header file for data structure Queue (helper for function wfs in BST)
 * Author: Maria Zharova
 * Created on 13.12.2019
 * (c) MIPT 2019
 */

#pragma once

#include "Binary_tree.h"

typedef struct Q_NODE* PQ_NODE;
typedef struct QUEUE* PQUEUE;

typedef struct _Q_NODE
{
	PTREE_NODE ptr;
	PQ_NODE next;
} Q_NODE;

typedef struct _QUEUE
{
	PQ_NODE head;
	PQ_NODE tail;
	int size;
} QUEUE;

/*
 * Create new queue
 * Arguments:
 *     none
 * Returns pointer to the created queue
 */
PQUEUE  create_queue(void);

/*
 * Insert element into queue
 * Arguments:
 *     q - pointer to the queue
 *	   ptr - pointer to the tree
 * Returns pointer to the inserted element
 */
void queue_push(PQUEUE q, PTREE_NODE ptr);

/*
 * Remove element from the queue
 * Arguments:
 *     q - pointer to the queue
 * Returns pointer to the inserted element
 */
void  queue_pop(PQUEUE q);


