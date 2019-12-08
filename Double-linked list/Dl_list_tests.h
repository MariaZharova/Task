/*
 * File:  dl_list_test.h
 * Brief: Header file for double linked list testing
 * Created on 08.12.2019
 * Author Maria Zharova <MZharovaNN@yandex.ru>
 * (c) MIPT 2019
 */

#pragma once

typedef int(*TEST)(void);

/*
* Two next functions for colorful messages
*/
void init_tests();
void deinit_tests();

/*
* Function for run all tests
*/
int run_all_tests();

/*
* Helper function that fill the list with values
*/
void infill(LIST* list, int n);

/*
* Function for run one test
*/
void run_test(int num, char* description, TEST test);

/*
* Test for function list_new
*/
int test_list_new(void);

/*
* Test for function list_del
*/
int test_list_del(void);

/*
* Test for function push
*/
int test_push(void);

/*
* Test for function pop
*/
int test_pop(void);

/*
* Test for function unshift
*/
int test_unshift(void);

/*
* Test for function shift
*/
int test_shift(void);

/*
* Test for function reverse
*/
int test_reverse(void);

/*
* Test for function print
*/
int test_print(void);