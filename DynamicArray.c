#include "DynamicArray.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

Array* init_array(int type_size, int capacity, void (struct Array*), int (*comparator)(void*, void*)) {
    Array* array = (Array*)malloc(sizeof(Array));
    if (!array) return NULL;

    array->capacity = capacity;
    array->size = 0;
    array->type_size = type_size;
    array->comparator = comparator;
    
    array->data = (void**)malloc(sizeof(void*) * capacity);
    if (!array->data) {
        free(array);
        return NULL;
    }
    
    return array;
}

void push_array(Array* array, void* ptr_item) {
    if (array->size >= array->capacity) {
        printf("Error: Array capacity reached (%d)\n", array->capacity);
        return;
    }

    array->data[array->size] = malloc(array->type_size);
    if (!array->data[array->size]) {
        printf("Error: Memory allocation failed\n");
        return;
    }

    memcpy(array->data[array->size], ptr_item, array->type_size);
    array->size++;
}

void print_array(Array* array) {
    if (!array || !array->data) {
        printf("Empty array\n");
        return;
    }

    printf("Array contents (%d/%d):\n", array->size, array->capacity);
    
    for (int i = 0; i < array->size; i++) {
        
        switch (array->type_size) {
            case sizeof(int):  
                printf("[%d] %d\n", i, *(int*)array->data[i]);
                break;
                
            case sizeof(char*):  
                printf("[%d] %s\n", i, (char*)array->data[i]);
                break;
                
            default:
                printf("[%d] (unknown type)\n", i);
                break;
        }
    }
    printf("\n");
}

void free_array(Array* array) {
    for (int i = 0; i < array->size; i++)
        free(array->data[i]);

    free(array->data);
}

void sort_array(Array* array) {
    if (!array || !array->comparator || array->size <= 1) return;

    for (int i = 0; i < array->size - 1; i++) {
        for (int j = 0; j < array->size - i - 1; j++) {
            if (array->comparator(array->data[j], array->data[j+1]) > 0) {
                void* temp = array->data[j];
                array->data[j] = array->data[j+1];
                array->data[j+1] = temp;
            }
        }
    }
}

Array* map(Array* array, void* (*process)(void*)) {
    Array* new_array = init_array(array->type_size, array->size, array->print, array->comparator);
    if (!new_array) return NULL;

    for (int i = 0; i < array->size; i++) {
        void* new_element = process(array->data[i]);
        if (!new_element) {
            free_array(new_array);
            return NULL;
        }
        push_array(new_array, new_element);
        free(new_element);
    }

    return new_array;
}

Array* where(Array* array, int (*is_suitable)(void*)) {
    
    int count = 0;
    for (int i = 0; i < array->size; i++) {
        if (is_suitable(array->data[i])) {
            count++;
        }
    }

    Array* new_array = init_array(array->type_size, count, array->print, array->comparator);
    if (!new_array) return NULL;

    for (int i = 0; i < array->size; i++) {
        if (is_suitable(array->data[i])) {
            push_array(new_array, array->data[i]);
        }
    }

    return new_array;
}

Array* concatenation(Array* left, Array* right) {
    if (left->type_size != right->type_size ||
        left->print != right->print ||
        left->comparator != right->comparator) {
        return NULL;
    }

    Array* new_array = init_array(left->type_size, left->size + right->size, left->print, left->comparator);
    if (!new_array) return NULL;

    for (int i = 0; i < left->size; i++) {
        push_array(new_array, left->data[i]);
    }

    for (int i = 0; i < right->size; i++) {
        push_array(new_array, right->data[i]);
    }

    return new_array;
}