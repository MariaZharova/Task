#include "common.h"

unsigned int hash(char* last_name)
{
	int s = 0;
	while (*last_name)
	{
		s += *last_name++;
	}
	return s % N;
}

void hash_map_init(void)
{

}

void hash_map_deinit(void)
{
	int i = 0;
	for (i = 0; i < N; i++)
	{
		if (NULL != hash_map[i]->first->val.last_name) {
			free(hash_map[i]->first->val.last_name);
		}
	}
}

char* make_str(char* str)
{
	char* new_str = (char*)malloc(sizeof(strlen(str) + 1));
	if (NULL == new_str)
	{
		exit(-1);
	}
	strcpy(new_str, str);
	return new_str;
}

void add(char* last_name, unsigned long long number)
{
	unsigned int index = hash(last_name);
	PERSON node;
	node.number = number;
	node.last_name = make_str(last_name);
	if (NULL == hash_map[index])
	{
		hash_map[index] = list_new();
	}
	unshift(hash_map[index], node);
}

LIST* find(char* last_name)
{
	unsigned int index = hash(last_name);
	if (NULL != hash_map[index])
	{
		return hash_map[index];
	}
}

/*
int del(char *last_name)
{
unsigned int index = hash(last_name);
if (NULL == hash_map[index].last_name)
{
return -1;
}
if (NULL != hash_map[index].last_name)
{
free(hash_map[index].surname);
}
hash_map[index].surname = NULL;
return index;
}
*/