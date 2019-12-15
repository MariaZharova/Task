/*
* This file is task.c
* Single linked list task file
* Author Abubakr Usmanov <usmanov.aa@phystech.edu>
* Created 07.12.2019
*/


#include "Common.h"

plist first_N_integers(int N)
{
	if (N == 0)
	{
		return NULL;
	}
	plist list;
	list = create_list();
	int i = 0;
	for (i = 1; i <= N; i++)
	{
		insert_entry(list, i);
	}
	print_list(list);
	return list;
}
