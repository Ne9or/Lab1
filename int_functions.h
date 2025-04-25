#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "DynamicArray.h"

void print_integers(Array* Array);

int compare_int(void* p1, void* p2);

void generate_int_data(Array* Array, int min, int max, int size);

int is_even(void* p);

void* cube(void* p);

Array* input_int_array();

