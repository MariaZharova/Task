	/*
	* File:  dl_list_tests.c
	* Brief : Double linked list testing implementations
	* Created on 08.12.2019
	* Author Maria Zharova <MZharovaNN@yandex.ru>
	* (c)MIPT 2019
	*/

	#include "common.h"
	#include <assert.h>
	#include "color.h"
	#include "Dl_list_tests.h"

	#define ERROR_LIST_NEW -1
	#define ERROR_DELETE -2
	#define ERROR_PUSH -3
	#define ERROR_POP -4
	#define ERROR_UNSHIFT -5
	#define ERROR_SHIFT -6
	#define ERROR_REVERSE -7

	void infill(LIST* list, int n)
	{
		int i = 0;
		for (i = 0; i < n; i++)
		{
			push(list, i);
			list->size++;
		}
	}

	int find_element(LIST* list, int value)
	{
		int f = 0;
		LIST_NODE* curr = list->head;
		while (NULL != curr)
		{
			if (curr->val == value)
				f = 1;
			curr = curr->next;
		}
		return f;
	}

	int test_list_new(void)
	{
		LIST* list = list_new();
		if (NULL == list)
		{
			printf("test_list_new: fail\n");
			return ERROR_LIST_NEW;
		}

		if (NULL != list->head)
		{
			printf("test_list_new: fail\n");
			return ERROR_LIST_NEW;
		}
		printf("test_list_new: passed\n");
		list_del(list);
		return 0;
	}

	int test_list_del(void)
	{
		LIST* list = list_new();
		infill(list, 30);
		list_del(list);
		if (NULL != list)
		{
			printf("test_list_del: fail\n");
			return ERROR_DELETE;
		}
		printf("test_list_del: passed\n");
		return 0;
	}

	int test_push(void)
	{
		LIST* list = list_new();
		int i = 0, counter = 0, f = 1;
		infill(list, 50);
		for (i = 0; i < 50; i++)
		{
			if (find_element(list, i))
				counter++;
			else
				f = 0;
		}
		if (!f)
		{
			printf("test_push: fail\n");
			return ERROR_PUSH;
		}
		if (counter != list->size)
		{
			printf("test_push: fail\n");
			return ERROR_PUSH;
		}
		printf("test_push: passed\n");
		return 0;
	}

	int test_pop(void)
	{
		LIST* list = list_new();
		int* plist = NULL;
		int size = 0;
		pop(list, plist);
		if (NULL != plist)
		{
			printf("test_pop: fail\n");
			return ERROR_POP;
		}
		infill(list, 30);
		size = 30;

		LIST_NODE* next = list->tail;
	
		if (NULL == plist)
		{
			printf("test_pop: fail\n");
			return ERROR_POP;
		}
		if (list->size != size)
		{
			printf("test_pop: fail\n");
			return ERROR_POP;
		}
		if (find_element(list, list->tail) == 0)
		{
			printf("test_pop: fail\n");
			return ERROR_POP;
		}
		if (plist != list->tail)
		{
			printf("test_pop: fail\n");
			return ERROR_POP;
		}
		printf("test_pop: passed\n");
		return 0;
	}

	int test_unshift(void)
	{
		LIST* list = list_new();
		unshift(list, 20);
		if (list->head->val != 20)
		{
			printf("test_unshift: fail\n");
			return ERROR_UNSHIFT;
		}
		if (list->size != 1)
		{
			printf("test_unshift: fail\n");
			return ERROR_UNSHIFT;
		}
		infill(list, 20);
		unshift(list, 30);
		int size = 20;
		if (list->head->val!= 30)
		{
			printf("test_unshift: fail\n");
			return ERROR_UNSHIFT;
		}
		if (list->size != size + 1)
		{
			printf("test_unshift: fail\n");
			return ERROR_UNSHIFT;
		}
		printf("test_unshift: passed\n");
		return 0;
	}

	int test_shift(void)
	{
		LIST* list = list_new();
		int* plist = NULL;
		if (!shift(list, plist))
		{
			printf("test_shift: fail\n");
			return ERROR_SHIFT;
		}

		infill(list, 30);
		int size = 30;
		int* check_plist = list->head;
		printf("\n\n\n\n");

		if (plist != check_plist)
		{
			printf("test_shift: fail\n");
			return ERROR_SHIFT;
		}
		if (list->size != size - 1)
		{
			printf("test_shift: fail\n");
			return ERROR_SHIFT;
		}
		printf("test_shift: passed\n");
		return 0;
	}

	int test_reverse(void)
	{
		LIST* list = list_new(), * list_tmp = list_new();
		reverse(list);
		if (NULL != list)
		{
			printf("test_reverse: fail\n");
			return ERROR_REVERSE;
		}
		infill(list, 25);
		infill(list_tmp, 25);
		reverse(list);
		if (list_tmp->size != list->size)
		{
			printf("test_reverse: fail\n");
			return ERROR_REVERSE;
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
			printf("test_reverse: fail\n");
			return ERROR_REVERSE;
		}
		printf("test_reverse: passed\n");
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

	void run_test(int num, char* description, TEST test)
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

		return 0;
	}
