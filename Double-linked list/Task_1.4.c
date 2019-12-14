/*
 * File:  task_1.4.c
 * Brief: implementation of function brackets (task 1.4)
 * Author: Maria Zharova <MZharovaNN@yandex.ru>
 * Created on 10.12.2019
 * (c) MIPT 2019
 */

#include <stdio.h>
#include <string.h>
#include "dl_list.h"
#include "Task 1.4.h"

#define ERROR_INVALID_INPUT -1
#define CORRECT 10
#define INCORRECT -10

int brackets(char *str)
{
	LIST* list = list_new();
	int *tmp = NULL;
	int curr, returns;
	int i = 0;
	int len = strlen(str);
	for (i = 0; i < len; ++i)
	{
		if (str[i] != '{' || str[i] != '(' || str[i] != ')' || str[i] != '}')
		{
			printf("In input there are foreign characters, that are not brackets\n");
			return ERROR_INVALID_INPUT;
		}
		if (str[i] == '{' || str[i] == '(')
		{
			if (str[i] == '{')
			{
				curr = 1;
			}
			if (str[i] == '(')
			{
				curr = 2;
			}
			returns = push(list, curr); //because function push returns int
		}

		if (str[i] == '}' || str[i] == ')')
		{
			returns = pop(list, tmp); //because function pop returns int
			if (str[i] == '}' && *tmp != 1)
			{
				printf("The bracket expression is incorrect:(\n");
				return INCORRECT;
			}
			if (str[i] == ')' && *tmp != 2)
			{
				printf("The bracket expression is incorrect:(\n");
				return INCORRECT;
			}
		}
	}
	printf("The bracket expression is correct!\n");
	return CORRECT;
}