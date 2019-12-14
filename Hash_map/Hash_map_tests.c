/*
 * File:  hash_map_tests.c
 * Brief: Hash map testing implementations
 * Created on 09.12.2019
 * Author Maria Zharova <MZharovaNN@yandex.ru>
 * (c) MIPT 2019
 */

#include "common.h"
#include <assert.h>
#include "color.h"
#include "hash_map_tests.h"
#define ERROR_INIT_DEINIT -1
#define ERROR_ADD_FIND2 -2
#define ERROR_DEL_FIND1 -3
#define K 1000

int test_init_deinit()
{
	hash_map_init(hash_table);
	int i, c;
	for (i = 0; i < K; ++i)
	{
		c = i % 256;
		add(&((char)(c)), 10);
	}
	hash_map_deinit(hash_table);
	for (i = 0; i < K; ++i)
	{
		if (NULL != hash_table[i])
		{
			printf("test_init_deinit: fail.\n");
			return ERROR_INIT_DEINIT;
		}
	}
	printf("test_init_deinit: passed.\n");
	return 0;
}

int test_add_find()  ///TODO find2
{
	hash_map_init(hash_table);
	int i, c;
	srand(time(NULL));
	for (i = 0; i < K; ++i)
	{
		c = (char)(rand() % 256);
		add(&((char)(c)), 10);
		if (NULL == find(&((char)(c)), 10))  //////////TODO: find2
		{
			printf("test_add: fail.\n");
			return ERROR_ADD_FIND2;
		}
	}
	hash_map_deinit(hash_table);
	printf("test_add: passed.\n");
	return 0;
}

int test_del_find()    /////////TODO find1
{
	hash_map_init(hash_table);
	int i, c;
	srand(time(NULL));
	for (i = 0; i < K; ++i)
	{
		c = (char)(rand() % 256);
		add(&((char)(c)), 10);
	}
	for (i = 0; i < K; ++i)
	{
		c = (char)(rand() % 256);
		del(&((char)(c)));
		if (NULL != find(&((char)(c))))  /////////TODO find1
		{
			printf("test_del: fail.\n");
			return ERROR_DEL_FIND1;
		}
	}
	hash_map_deinit(hash_table);
	printf("test_del: passed.\n");
	return 1;
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

	run_test(++test_num, "Init and deinit hash map", test_init_deinit);
	run_test(++test_num, "Add element by name and number and find it", test_add_find2);
	run_test(++test_num, "Delete element by name and find it", test_del_find1);

	return 0;
}