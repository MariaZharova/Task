/*
* This file is dl_list.c
* Double linked list implementation
* Author Abubakr Usmanov <usmanov.aa@phystech.edu>
* Created 07.12.2019
*/

#include "common.h"

LIST* list_new()
{
	LIST* list = (LIST*)malloc(sizeof(LIST));
	if (NULL == list)
	{
		exit(-1);
	}
	list->first = NULL;
	return list;
}

int list_del(LIST* list)
{
	if (NULL == list)
	{
		return 1;
	}
	LIST_NODE* node = list->first;
	LIST_NODE* tmp;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	free(list);
	list = NULL;
	return 0;
}

int push(LIST* list, int data)
{
	LIST_NODE* new = (LIST_NODE*)malloc(sizeof(LIST_NODE));
	if (NULL == new)
	{
		return 1;
	}
	LIST_NODE* tmp;
	tmp = list->first;
	new->val = data;
	new->next = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	new->prev = tmp;
	tmp->next = new;
	return 0;
}

int pop(LIST* list, int* p)
{
	if (NULL == list)
	{
		return 1;
	}
	LIST_NODE* tmp = list->first;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	*p = tmp->val;
	return 0;
}

int unshift(LIST* list, int data)
{
	LIST_NODE* new = (LIST_NODE*)malloc(sizeof(LIST_NODE));
	if (NULL == new)
	{
		return 1;
	}
	new->val = data;
	new->next = list->first;
	new->prev = NULL;
	if (list->first)
	{
		list->first->prev = new;
	}
	list->first = new;
	return 0;
}

int shift(LIST* list, int* p)
{
	*p = list->first->val;
	return 0;
}

void reverse(LIST* list)
{
	LIST_NODE* node = list->first;
	LIST_NODE* tmp;
	while (node->next != NULL)
	{
		tmp = node->next;
		node->next = node->prev;
		node->prev = tmp;
		node = node->prev;
	}
	tmp = node->next;
	node->next = node->prev;
	node->prev = tmp;
	list->first = node;
}

void print(LIST* list)
{
	if (NULL == list)
	{
		printf("Error: Sthis list doesnt exist!");
		return;
	}
	LIST_NODE* node = list->first;
	printf("(");
	while (node->next != NULL)
	{
		printf("%d, ", node->val);
		node = node->next;
	}
	printf("%d)\n", node->val);
}