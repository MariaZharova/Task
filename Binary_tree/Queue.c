/*
 * File:  queue.c
 * Brief: Function implementation for data structure Queue (helper for function wfs in BST)
 * Author: Maria Zharova
 * Created on 13.12.2019
 * (c) MIPT 2019
 */

#include "common.h"

PQUEUE create_queue(void)
{
	PQUEUE q = malloc(sizeof(QUEUE));
	if (NULL == q)
	{
		printf("create_queue: Error, out of memory:(\n");
		return ERROR_OUT_OF_MEMORY;
	}
	q->head = NULL;
	q->tail = NULL;
	q->size = 0;
	return q;
}

void queue_push(PQUEUE q, PTREE_NODE ptr)
{
	PQ_NODE p = (PQ_NODE)malloc(sizeof(Q_NODE));
	if (NULL != p)
	{
		p->ptr = ptr;
		p->next = NULL;
		if (NULL == q->head)
		{
            q->head = q->tail = p;
		}	
		else 
		{
			q->tail->next = p;
			q->tail = p;
		}
	}
}


void  queue_pop(PQUEUE q)
{
	PQ_NODE t;
	if (NULL != q->head) 
	{
		t = q->head;
		q->head = q->head->next;
		free(t);
		if (NULL == q->head)
		{
            q->tail = NULL;
		}
	}
}