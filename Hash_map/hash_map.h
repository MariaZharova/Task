#pragma once

#include "hash_dl_list.h"
#define N 16

LIST* hash_map[N];

void hash_map_init(void);

void hash_map_deinit(void);

void add(char* last_name, unsigned long long number);

unsigned int del(char* last_name);

LIST * find(char* name);
