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
#define ERROR_ADD_FIND -2
#define ERROR_DEL_FIND -3
#define K 1000

char* a = "abcdefg";
char* b = "abcdefghijklmnop";
char* c = "abcdefghijklmnopqrstuvwxyz";
char* d = "							 ";
char* e = "1234567890";
unsigned int returns;

int test_deinit()
{
	hash_map_init();
	int i, c;
	for (i = 0; i < K; ++i)
	{
		c = i % 256;
		add(&((char)(c)), 10);
	}
	hash_map_deinit();
	for (i = 0; i < K; ++i)
	{
		if (NULL != hash_map[i])
		{
			printf("test_init_deinit: fail.\n");
			return ERROR_INIT_DEINIT;
		}
	}
	printf("test_init_deinit: passed.\n");
	return 0;
}

int test_add_find()
{
	hash_map_init();
	int i, c;
	srand(time(NULL));
	for (i = 0; i < K; ++i)
	{
		c = (char)(rand() % 256);
		add(&((char)(c)), 10);
		if (NULL == find(&(char)(c)))
		{
			printf("test_add_find: fail.\n");
			return ERROR_ADD_FIND;
		}
	}
	hash_map_deinit(hash_map);
	add(a, 10);
	add(b, 10);
	add(c, 10);
	add(d, 10);
	add(e, 10);
	if (NULL == find(a) || NULL == find(b) || NULL == find(c) || NULL == find(d) || NULL == find(e))
	{
		printf("test_add_find: fail.\n");
		return ERROR_ADD_FIND;
	}
	printf("test_add_find: passed.\n");
	return 0;
}

int test_del_find()
{
	hash_map_init();
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
		returns = del(&((char)(c)));  //because function del returns int
		if (NULL != find(&((char)(c))))
		{
			printf("test_del_find: fail.\n");
			return ERROR_DEL_FIND;
		}
	}
	add(a, 10);
	add(b, 10);
	add(c, 10);
	add(d, 10);
	add(e, 10);
	returns = del(a);
	returns = del(b);
	returns = del(c);
	returns = del(d);
	returns = del(e);
	if (NULL != find(a) || NULL != find(b) || NULL != find(c) || NULL != find(d) || NULL != find(e))
	{
		printf("test_del_find: fail.\n");
		return ERROR_DEL_FIND;
	}
	hash_map_deinit(hash_map);
	printf("test_del_find: passed.\n");
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

	run_test(++test_num, "Init and deinit hash map", test_deinit);
	run_test(++test_num, "Add element by name and number and find it", test_add_find);
	run_test(++test_num, "Delete element by name and find it", test_del_find);

	return 0;
}
