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
pslist list;

list = slist_new();
printf("List created! %p\n", list);
slist_insert(list, 1);
slist_insert(list, 2);
slist_insert(list, 3);
slist_print(list);

slist_delete(list);
return 0;
}

int test2()
{
pslist list = slist_new();

if (NULL != list->head)
goto error_path;
if (0 != list->list_size)
goto error_path;

slist_delete(list);
return 0;
error_path:
slist_delete(list);
return -1;
}

int test3()
{
pslist list = slist_new();

slist_insert(list, 1);
slist_insert(list, 1);
slist_insert(list, 2);
slist_remove(list, 1);

int result = (list->list_size != 1)? -1:0;
slist_delete(list);
return result;
}

int main(void)
{
printf("Hello, " "world!" "\n");
test1();
printf("TEST #2 Create list:\t\t%s%s\n", (test2() == 0)? KGRN"PASSED":KRED"FAILED", KWHT); // or KBLK
printf("TEST #3 Remove element:\t\t%s%s\n", (test3() == 0)? KGRN"PASSED":KRED"FAILED", KWHT);

return 0;
}