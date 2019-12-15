/*
* This file is Sl_list.h
* Single linked list header
* Author Maria Zharova <MZharovaNN@yandex.ru>
* Created 11.11.2019
*/

#pragma once

typedef struct _list_entry* plist_entry;
typedef struct _list* plist;

typedef struct _list_entry
{
	int value;
	plist_entry next;
}list_entry, * plist_entry;

typedef struct _list
{
	int size;
	plist_entry head;
}list, * plist;

/*
* Create single sinked list
* Parameters
*    none
* Returns pointer to list head
*/
plist create_list(void);

/*
* Destroy list
* Parameters
*    list - pointer to list head
* Returns none
*/
int destroy_list(plist list);

/*
* Insert new element to list
* Parameters
*    list - pointer to list head, value - value of new element
* Returns pointer to the added element
*/
plist_entry insert_entry(plist list, int value);

/*
* Delete elements from list
* Parameters
*    list - pointer to list head, value - value of elements, which are need to delete
* Returns amount of deleted elements
*/
int delete_entry(plist list, int value);

/*
* Find element in list
* Parameters
*    list - pointer to list head, value - value of the desired element
* Returns amount of desired elements in the list
*/
int find_entry(plist list, int value);

/*
* Print all list
* Parameters
*    list - pointer to list head
* Returns none
*/
void print_list(plist list);
