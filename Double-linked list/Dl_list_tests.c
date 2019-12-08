/*
 * File:  dl_list_test.c
 * Brief: Double linked list testing implementations
 * Created on 08.12.2019
 * Author Maria Zharova <MZharovaNN@yandex.ru>
 * (c) MIPT 2019
 */

#include "common.h"
#include <assert.h>
#include "color.h"
#include "dl_list_test.h"
#define ERROR_LIST_NULL -1
#define ERROR_HEAD_NOT_NULL -2
#define ERROR_DELETE -3
#define ERROR_SIZE -4
#define ERROR_REVERSE -5
#define ERROR_UNSHIFT -6
#define ERROR_POP -7

int test_list_new(void)
{
    printf("Creating new list...\n");
    LIST *list = list_new();
    if (NULL == list)
    {
        printf("Fail to create list\n");
        return ERROR_LIST_NULL;
    }

    if (NULL != list->head)
    {
        printf("Fail: first element is not NULL\n");
        return ERROR_HEAD_NOT_NULL;
    }
	printf("Test_list_new has been passed!\n");
    printf("Deleting list...\n");
    list_del(list);
    return 0;
}

void infill(LIST* list, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		push(list, i);
	}
}

int find_elem(LIST* list, int value)
{
	int f = 0;
	LIST_NODE *curr = list->head;
	while (NULL != curr)
	{
		if (curr->value == value)
			f = 1;
		curr = curr->next;
	}
	return f;
}

int test_list_del(void)
{
	LIST* list = list_new();
	infill(list, 30);
	list_del(list);
	if (NULL != list)
	{
		printf("Fail: list wasn't deleted\n");
		return ERROR_DELETE;
	}
	printf("Test_list_del has been passed!\n");
	return 0;
}

int test_push(void)
{
	LIST *list = list_new();
	int i = 0, counter = 0, f = 1;
	infill(list, 50);
	for (i = 0; i < 50; i++)
	{
		if (find_elem(list, i))
			counter++;
		else
			f = 0;
	}
	if (!f)
	{
		printf("ERROR in test_push: element was not pushed!\n");
		return ERROR_PUSH;
	}
	if (count != list->size)
	{
		printf("Error: amount of element is not equal size of list\n");
		return ERROR_SIZE;
	}
	printf("Test_push has been passed!\n");
	return 0;
}

int test_pop(void)
{
	LIST *list = list_new();
	int *plist = NULL;
	int size = 0;
	pop(list, plist);
	if (NULL != plist)
	{
		printf("Error, pointer is NULL\n");
		return ERROR_POP;
	}
	infill(list, 30);
	size = 30;
	LIST_NODE* next = list->next;
	pop(list, plist);
	if (NULL == plist)
	{
		printf("Error, pointer is NULL\n");
		return ERROR_POP;
	}
	if (list->size != size - 1)
	{
		printf("Error: wrong size of list!\n");
		return ERROR_SIZE;
	}
	if (find_element(list, tail) == 0)
	{
		printf("Error: element was not deleted\n");
		return ERROR_POP;
	}
	if (plist != tail)
	{
		printf("Error: pointer is wrong\n");
		return ERROR_POP;
	}
	printf("PASS: test_pop\n");
	return 0;
}

int test_unshift(void)
{
	LIST *list = list_new();
	unshift(list, 20);
	if (list->head->value != 20)
	{
		printf("Error: element was not added to the list!\n");
		return ERROR_UNSHIFT;
	}
	if (list->size != 1)
	{
		printf("Error: wrong size of the list!\n");
		return ERROR_SIZE;
	}
	fill_list(list, 20);
	unshift(list, 30);
	int size = 20;
	if (list->head->value != 30)
	{
		printf("Error: element was not added to the list\n");
		return ERROR_UNSHIFT;
	}
	if (list->size != size + 1)
	{
		printf("Error: wrong size of the list!\n");
		return ERROR_SIZE;
	}
	printf("Test_unshift has been passed\n");
	return 0;
}

int test_shift(void)
{
	LIST *list = list_new();
	int *plist = NULL;
	if (!shift(list, plist))
	{
		printf("Deleting from empty list has failed\n");
		return ERROR_SHIFT;
	}
	infill(list, 30);
	int size = 30;
	int *check_plist = list->head;
	shift(list, plist);
	if (plist != check_plist)
	{
		printf("Error: pointer is wrong\n");
		return ERROR_SHIFT;
	}
	if (list->size != size - 1)
	{
		printf("Error: wrong size of the list\n");
		return ERROR_SIZE;
	}
	printf("Test_shift has been passed!\n");
	return 0;
}

int test_reverse(void)
{
	LIST *list = list_new(), *list_tmp = list_new();
	reverse(list);
	if (NULL != list)
	{
		printf("Error: reversing list is NULL\n");
		return ERROR_LIST_NULL;
	}
	infill(list, 25);
	infill(list_tmp, 25);
	reverse(list);
	if (list_tmp->size != list->size)
	{
		printf("Error: wrong size of reversed list!\n");
		return ERROR_SIZE;
	}
	int f = 1;
	LIST_NODE* current_tmp = list_tmp->head;
	LIST_NODE* current = list->tail;
	while (current != list_tmp->tail)
	{
		if (current != current_tmp)
		{
			f = 0;
		}
		current_tmp = current_tmp->next;
		current = current->prev;
	}
	if (!f)
	{
		printf("Elements were not reversed correctly:(\n");
		return ERROR_REVERSE;
	}
	printf("Test_reverse has been passed!\n");
	return 0;
}

int test_print(void)
{
    LIST *list = list_new();
	infill(list, 30);
	print(list);
	printf("There should be 30 elements\n");
	//TODO
	return 0;
}


void init_tests()
{
    init_color();
}

void deinit_tests()
{
    deinit_color();
}

void run_test(int num, char *description, TEST test)
{
    printf("TEST #%d %s:\t\tExecution\n", num, description);
    int result = test();
    printf("TEST #%d %s:\t\tExecution completed with code 0x%08x\n", num, description, result);
    printf("TEST #%d %s:\t\t", num, description);
    (result == 0) ? print_color(COLOR_GREEN, "PASS\n") : print_color(COLOR_RED, "FAIL\n");
}

int run_all_tests()
{
    printf("Run all tests:\n");
    int test_num = 0;

    run_test(++test_num, "Create list", test_list_new);
	run_test(++test_num, "Delete list", test_list_del);
	run_test(++test_num, "Push in list", test_push);
	run_test(++test_num, "Pop from list", test_pop);
	run_test(++test_num, "Shift in list", test_shift);
	run_test(++test_num, "Unshift from list", test_unshift);
	run_test(++test_num, "Reverse list", test_reverse);
    run_test(++test_num, "Print list", test_print);

    return 0;
}
