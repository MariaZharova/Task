/*
* This file is Sl_list.c
* Single linked list implementation
* Author Maria Zharova <MZharovaNN@yandex.ru>
* Created 11.11.2019
*/

#include <stdio.h>
#include <stdlib.h>
#include "Sl_list.h"
#define ERROR_OUT_OF_MEMORY NULL
#define ERROR_INVALID_INPUT NULL
#define ERROR_INVALID_INPUT_INT -1

plist create_list(void)
{
	plist first;
	first = malloc(sizeof(list));
	if (NULL == first)
	{
		printf("create_list: Error, out of memory:(\n");
		return ERROR_OUT_OF_MEMORY;
	}
	first->size = 0;
	first->head = NULL;

	return first;
}

int destroy_list(plist first)
{
	if (NULL == first)
	{
		printf("destroy_list: Error, the pointer to list is NULL\n");
		return 1;
	}
	plist_entry head = first->head;
	plist_entry tmp1, tmp2;
	tmp1 = head->next;
	while (NULL != tmp1)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
	free(head);
	printf("destroy_list: The all list has been deleted.\n");
	return 1;
}

plist_entry insert_entry(plist first, int value)
{
	if (NULL == first)
	{
		printf("insert_entry: Error, the pointer to list is NULL\n");
		return ERROR_INVALID_INPUT;
	}
	plist_entry pnew;
	pnew = malloc(sizeof(list_entry));
	if (NULL == pnew)
	{
		printf("insert_entry: Error, out of memory:(\n");
		return ERROR_OUT_OF_MEMORY;
	}
	pnew->next = first->head;
	pnew->value = value;
	printf("insert_entry: It's OK. New element is %d\n", pnew->value);
	first->head = pnew;
	first->size++;
	return pnew;
}

int delete_entry(plist first, int value)
{
	if (NULL == first)
	{
		printf("delete_entry:Error, the pointer to list is NULL\n");
		return ERROR_INVALID_INPUT_INT;
	}
	plist_entry curr = first->head;
	plist_entry prev = curr->next;
	int counter = 0;
	do
	{
		if (curr->value == value)
		{
			if (NULL != prev)
			{
				prev->next = curr->next;
				free(curr);
				curr = NULL;
				counter++;
			}
			else
			{
				plist_entry new_first = first->head->next;
				first->head = new_first;
				counter++;
			}
		}
		prev = curr;
		curr = curr->next;
	} while (NULL != curr);
	return counter;
}

int find_entry(plist first, int value)
{
	if (NULL == first)
	{
		printf("find_entry: Error, the pointer to list is NULL\n");
		return ERROR_INVALID_INPUT_INT;
	}
	plist_entry tmp = first->head;
	int i, counter = 0, n = first->size;
	for (i = 0; i < n; ++i)
	{
		if (tmp->value == value)
		{
			counter++;
			printf("find_entry: Such element in %d place\n", i);
		}
		tmp = tmp->next;
	}
	printf("find_entry: %d elements with value %d were found in the list\n", counter, value);
	return counter;
}

void print_list(plist first)
{
	plist_entry pcurr = first->head;
	printf("Print list:\n");
	while (NULL != pcurr)
	{
		printf("> %d\n", pcurr->value);
		pcurr = pcurr->next;
	}
}
