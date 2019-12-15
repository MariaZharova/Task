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
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	return list;
}

list_del(LIST* list)
{
	LIST_NODE* current = list->head;
	LIST_NODE* next = NULL;
	while (NULL != current) {
		next = current->next;
		free(current);
		current = next;
	}
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	free(list);
	return 0;
}

int unshift(LIST* list, int value)
{
	LIST_NODE* Newlist = (LIST_NODE*)malloc(sizeof(LIST_NODE));
	LIST_NODE* NextNewlist = (LIST_NODE*)malloc(sizeof(LIST_NODE));

	if (NULL == Newlist)
	{
		printf("Error: Can't allocate memory");
		exit(1);
	}

	Newlist->val = value;

	if (NULL != list->head)
	{
		Newlist->prev = NULL;
		Newlist->next = list->head;
		NextNewlist = list->head;
		NextNewlist->prev = Newlist;
		list->head = Newlist;
		list->size++;
	}

	else
	{
		Newlist->prev = NULL;
		Newlist->next = NULL;
		list->head = Newlist;
		list->tail = Newlist;
		list->size = 1;
	}
	return 0;
}

int shift(LIST* list, int* pointer)
{
	if (NULL != list->head)
	{
		LIST_NODE* Firstlist = list->head;
		*pointer = (int)(Firstlist->val);
		return 0;
	}
	else
	{
		printf("First element doesn't exist");
		return 1;
	}
}

int pop(LIST* list, int* pointer)
{
	if (NULL != list->tail)
	{
		LIST_NODE* Lastlist = list->tail;
		*pointer = (int)(Lastlist->val);
		return 0;
	}
	else
	{
		printf("Last element doesn't exist");
		return 1;
	}
}

int push(LIST* list, int value)
{
	LIST_NODE* Newlist = (LIST_NODE*)malloc(sizeof(LIST_NODE));
	LIST_NODE* PrevNewlist = (LIST_NODE*)malloc(sizeof(LIST_NODE));

	if (NULL == Newlist)
	{
		printf("Error: Can't allocate memory");
		exit(1);
	}

	Newlist->val = value;

	if (NULL != list->tail)
	{
		Newlist->next = NULL;
		Newlist->prev = list->tail;
		PrevNewlist = list->tail;
		PrevNewlist->next = Newlist;
		list->tail = Newlist;
		list->size++;
	}
	else
	{
		list->head = Newlist;
		list->tail = Newlist;
		list->size = 1;
		Newlist->next = NULL;
		Newlist->prev = NULL;
	}

	return 0;
}

void print(LIST* list)
{
	LIST_NODE* current = NULL;

	if (NULL != list->head)
	{
		current = list->head;
	}
	else
	{
		printf("List is empty");
	}

	while (NULL != current)
	{
		if (current->val == NULL)
		{
			printf("Error: value = NULL");
		}
		else
		{
			printf("%d ", current->val);
		}
		current = current->next;
	}
}

void reverseprint(LIST* list)
{
	LIST_NODE* current = NULL;

	if (NULL != list->tail)
	{
		current = list->tail;
	}
	else
	{
		printf("List is empty");
	}

	while (NULL != current)
	{
		printf("%d ", current->val);
		current = current->prev;
	}
}

void reverse(LIST* list)
{
	LIST_NODE* current;
	LIST_NODE* tmp;
	current = list->head;
	while (current != NULL)
	{
		tmp = current->next;
		current->next = current->prev;
		current->prev = tmp;
		current = current->prev;
	}
	current = list->head;
	list->head = list->tail;
	list->tail = current;
}
