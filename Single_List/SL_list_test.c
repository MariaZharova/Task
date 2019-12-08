/*
* This file is Sl_list_test.c
* Single linked list test file
* Author Abubakr Usmanov <usmanov.aa@phystech.edu>
* Created 07.12.2019
*/

#include <stdio.h>
#include "Sl_list.h"

#define KRED "\x1B[31m" // red
#define KGRN "\x1B[32m" // green
#define KWHT "\x1B[37m" // white
#define KBLK "\x1B[30m" // black

int test1()
{
	plist list;

	list = create_list();
	printf("List created! %p\n", list);
	insert_entry(list, 1);
	insert_entry(list, 2);
	insert_entry(list, 3);
	print_list(list);

	destroy_list(list);
	return 0;
}

int test2()
{
	plist list = create_list();

	if (NULL != list->head)
		goto error_path;
	if (0 != list->size)
		goto error_path;

	destroy_list(list);
	return 0;
error_path:
	destroy_list(list);
	return -1;
}

int test3()
{
	plist list = create_list();

	insert_entry(list, 1);
	insert_entry(list, 1);
	insert_entry(list, 2);
	delete_entry(list, 1);

	int result = (list->size != 1) ? -1 : 0;
	destroy_list(list);
	return result;
}

int main(void)
{
	printf("Hello, " "world!" "\n");
	test1();
	printf("TEST #2 Create list:\t\t%s%s\n", (test2() == 0) ? KGRN"PASSED" : KRED"FAILED", KWHT); // or KBLK
	printf("TEST #3 Remove element:\t\t%s%s\n", (test3() == 0) ? KGRN"PASSED" : KRED"FAILED", KWHT);

	return 0;
}
