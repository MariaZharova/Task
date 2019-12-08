#pragma once

typedef struct _PERSON
{
	char* last_name;
	unsigned long long number;
} PERSON, *PPERSON;

typedef struct _NODE
{
	PERSON val;
	struct _NODE* prev;
	struct _NODE* next;
} NODE;

typedef struct _LIST
{
	NODE* first;
} LIST;

LIST* list_new();

int list_del(LIST* list);

int unshift(LIST* list, PERSON smb);

int find_l(LIST* list, PERSON* psmb);

void print_dl_list(LIST* list);


