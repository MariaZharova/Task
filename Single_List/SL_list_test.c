/*
* This file is Sl_list_test.c
* Single linked list test file
* Author Abubakr Usmanov <usmanov.aa@phystech.edu>
* Created 07.12.2019
*/

#include"Common.h"

int test1()
{
	plist list;

	list = create_list();
	printf("List created! %p\n", list);
	insert_entry(list, 1);
	insert_entry(list, 2);	
	insert_entry(list, 3);
	print_list(list);

	int k = destroy_list(list);
	return 0;
}

int test2()
{
	plist list1 = create_list();

	if (NULL != list1->head)
	{
		int k = destroy_list(list1);
		return -1;
	}
	if (0 != list1->size)
	{
		int k = destroy_list(list1);
		return -1;
	}
	list1 = first_N_integers(4);
	int k = destroy_list(list1);

	return 0;
}

int test3()
{
	plist list2 = create_list();

	insert_entry(list2, 1);
	insert_entry(list2, 1);
	insert_entry(list2, 2);
	delete_entry(list2, 1);

	int result = (list2->size != 1) ? -1 : 0;
	int k = destroy_list(list2);
	return result;
}
