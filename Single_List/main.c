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
	printf("TEST #2 Create list:\t\t%s\n", (test2() == 0) ? "PASSED" : "FAILED");
	printf("TEST #3 Remove element:\t\t%s\n", (test3() == 0) ? "PASSED" : "FAILED");
	return 0;
}
