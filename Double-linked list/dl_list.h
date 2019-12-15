/*
* This file is dl_list.h
* Double linked list header file
* Author Abubakr Usmanov <usmanov.aa@phystech.edu>
* Created 07.12.2019
*/

#pragma once

typedef struct _LIST_NODE
{
	int val;
	struct _LIST_NODE* prev;
	struct _LIST_NODE* next;
} LIST_NODE;

typedef struct _LIST
{
	int size;
	LIST_NODE* head;
	LIST_NODE* tail;
} LIST;

LIST* list_new();
/*
fuction:			list_new() creates new empty list
arguments:			none
returning values:	Link to the list if list is created
					1 if list isn`t created
*/

int list_del(LIST* list);
/*
function:			list_del(LIST* list) deletes list and all elements in it
arguments:			LIST* list (pointer to the head of the List)
returning values:	0 if opetation successfully complited
					1 if operation didn't successfully complited
*/

int push(LIST* list, int data);
/*
function:			push(LIST* list, int data) adds new element in the end of the list
arguments:			LIST* list (pointer to the head of the List)
					int data (pushing number)
returning values:	0 if opetation successfully complited
					1 if operation didn't successfully complited
*/

int pop(LIST* list, int* p);
/*
function:			pop(LIST* list, int data) gets the Last element of the list
arguments:			LIST* list (pointer to the head of the list)
					int* p (pointer where to push popped element)
returning values:	0 if opetation successfully complited
					1 if operation didn't successfully complited
*/

int unshift(LIST* list, int data);
/*
function:			unshift(LIST* list, int data) adds new element in the beginning of the list
arguments:			LIST* list (pointer to the head of the List)
					int data (new value)
returning values:	0 if opetation successfully complited
					1 if operation didn't successfully complited
*/

int shift(LIST* list, int* data);
/*
function:			shift(LIST* list, int* p) gets the first element of the list
arguments:			LIST* list (pointer to the head of the List)
					int* p (address where to put the element)
returning values:	0 if opetation successfully complited
					1 if operation didn't successfully complited
*/

void reverse(LIST* list);
/*
function:			reverse(LIST* list) reverses list
arguments:			LIST* list (pointer to the head of the List)
returning values:	none
*/

void print(LIST* list);
/*
function:			print(LIST* list) prints list
arguments:			LIST* list (pointer to the head of the List)
returning values:	none
*/
