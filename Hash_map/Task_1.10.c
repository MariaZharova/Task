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

void INSERT_TASK(char *name, unsigned long long number)
{
	unsigned long long X = 0;
	if (NULL == find(name))
	{
		add(name, number);
		printf("OK\n");
	}
	else
	{
		X = find(name)->first->val.number;
		del(name);
		add(name, number);
		printf("Changed. Old value = %llu\n", X);
	}
}

void FIND_TASK(char* name)
{
	if (NULL == find(name)) 
	{
		printf("NO\n");
	}
	else
	{
		printf("%llu", find(name)->first->val.number);
	}
}
