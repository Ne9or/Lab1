#pragma once

#include <stdlib.h>

#define INTEGER 0
#define CHAR 1

struct Array {
    int capacity;
    int size;
    int type_size;
    void** data;
    void (*print)(struct Array*);
    int (*comparator)(void*, void*);
};

typedef struct Array Array;

Array* init_array(int type_size,int capacity, void (struct Array*), int (*comparator)(void*, void*));

void push_array(Array* array, void* ptr_item);

void print_array(Array* array);

void free_array(Array* array);

void sort_array(Array* array);

Array* concatenation(Array* left, Array* right);

Array* where(Array* array, int (*is_suitable)(void*));

Array* map(Array* array, void* (*process)(void*));
