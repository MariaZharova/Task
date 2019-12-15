/*
 * File:  task_1.10.c
 * Brief: header file for task 1.10 from zadavalnik
 * Author: Maria Zharova <MZharovaNN@yandex.ru>
 * Created on 14.12.2019
 * (c) MIPT 2019
 */

#pragma once

 /*
 * Insert new name and number into table
 * Parameters
 *    name - pointer to the person's name
 *    number - value of person's phone number
 * Returns none
 */
void INSERT_TASK(char* name, unsigned long long number);

/*
* Find name in the table
* Parameters
*    name - pointer to the person's name
* Returns none
*/
void FIND_TASK(char* name);
