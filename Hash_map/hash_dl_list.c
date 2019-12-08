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
	if (list == NULL)
	{
		return 1;
	}
	NODE* node = list->first;
	NODE* tmp;
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

int unshift(LIST* list, PERSON smb)
{
	NODE* new = (NODE*)malloc(sizeof(NODE));
	if (NULL == new)
	{
		return 1;
	}
	new->val = smb;
	new->next = list->first;
	new->prev = NULL;
	if (list->first)
	{
		list->first->prev = new;
	}
	list->first = new;
	return 0;
}

void print_dl_list(LIST* list)
{
	if (NULL == list)
	{
		printf("Error: this list doesnt exist!");
		return;
	}
	NODE* node = list->first;
	printf("(");
	while (node->next != NULL)
	{
		printf("(%s : %llu), ", node->val.last_name, node->val.number);
		node = node->next;
	}
	printf("(%s : %llu))", node->val.last_name, node->val.number);
}