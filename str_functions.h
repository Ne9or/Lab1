#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "DynamicArray.h"

void print_strings(Array* array);

int compare_str(void* p1, void* p2);

int is_all_alphas(void* p);

void* to_uppercase(void* p);

Array* input_str_array();

