/*
* This file is main.c
* Single linked list main file
* Author Abubakr Usmanov <usmanov.aa@phystech.edu>
* Created 07.12.2019
*/


#include "Common.h"

int main(void)
{
	printf("Hello, " "world!" "\n");
	test1();
	printf("TEST #2 Create list:\t\t%s%s\n", (test2() == 0) ? KGRN"PASSED" : KRED"FAILED", KWHT); // or KBLK
	printf("TEST #3 Remove element:\t\t%s%s\n", (test3() == 0) ? KGRN"PASSED" : KRED"FAILED", KWHT);

	plist list;
	list = first_N_integers(5);
	print_list(list);
	destroy_list(list);

	return 0;
}