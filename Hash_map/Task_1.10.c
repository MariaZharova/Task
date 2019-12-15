/*
 * File:  task_1.10.c
 * Brief: solution of task 1.10 from zadavalnik
 * Author: Maria Zharova <MZharovaNN@yandex.ru>
 * Created on 10.12.2019
 * (c) MIPT 2019
 */

#include "common.h"
#include "Task_1.10.h"
#include <string.h>
#define COMMAND_SIZE 10
#define NAME_SIZE 30

void INSERT(char *name, unsigned long long number)
{
	unsigned long long X = 0;
	if (NULL == find(name))
	{
		add(name, number);
		printf("OK\n");
	}
	else
	{
		X = find(name)->head->value.number;
		del(name);
		add(name, number);
		printf("Changed. Old value = %llu\n", X);
	}
}

void FIND(char* name)
{
	if (NULL == find(name)) 
	{
		printf("NO\n");
	}
	else
	{
		printf("%llu", find(name)->head->value.number);
	}
}

int main(void)
{
	char c;
	char command[COMMAND_SIZE];
	char name[NAME_SIZE];
	unsigned long long number = 0;
	hash_map_init(); 
 	while ((c = getchar()) != '\0')
	{
		if (c != ',' && c!=' ')
		{
			ungetc(c, stdin);
		}
		else
		{
			continue;
		}

		scanf("%s %s", command, name);
		if (strcmp(command, 'INSERT') == 0)
		{
			scanf("%llu", &number);
			INSERT(name, number);
		}
		if (strcmp(command, 'FIND') == 0)
		{
			FIND(name);
		}
	}
	return 0;
}
