/*
 * File:  hash_map_test.h
 * Brief: Header file for hash map testing
 * Created on 08.12.2019
 * Author Maria Zharova <MZharovaNN@yandex.ru>
 * (c) MIPT 2019
 */

#pragma once

typedef int(*TEST)(void);

/*
* Two next functions for colorful messages
*/
void init_tests(void);
void deinit_tests(void);

/*
* Function for run all tests
*/
int run_all_tests(void);

/*
* Test for function hash_map_deinit
*/
int test_deinit(void);

/*
* Test for function add and find2
*/
int test_add_find(void);

/*
* Test for function del and find1
*/
int test_del_find(void);
