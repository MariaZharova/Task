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
void init_tests();
void deinit_tests();

/*
* Function for run all tests
*/
int run_all_tests();

/*
* Test for function hash_map_init and hash_map_deinit
*/
int test_init_deinit()

/*
* Test for function add and find2
*/
int test_add_find2()

/*
* Test for function del and find1
*/
int test_del_find1()






