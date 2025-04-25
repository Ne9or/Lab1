
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#include "str_functions.h"

#define SIZE 128 


void print_strings(Array* array) {
    printf("(%d): ", array->size);
    for (int i = 0; i < array->size; i++) {
        printf("%s ", (char*)(array->data[i]));
    }
    printf("\n");
}

int compare_str(void* p1, void* p2) {
    char* str1 = *(char**)p1;
    char* str2 = *(char**)p2;
    return strcmp(str1, str2);
}

int is_all_alphas(void* p) {
    char* s = (char*)p;

    for (int i = 0; s[i] != '\0'; i++) {
        if (!isalpha(s[i]))
            return 0;
    }

    return 1;
}

void* to_uppercase(void* p) {
    char* s = (char*)p;
    size_t len = strlen(s);
    char* new_s = (char*)malloc(len + 1);
    for (size_t i = 0; i < len; i++) {
        new_s[i] = toupper(s[i]);
    }
    new_s[len] = '\0';
    return (void*)new_s;
}

Array* input_str_array() {
    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);

    if (size <= 0) return NULL;

    Array* array = init_array(sizeof(char*), size, print_strings, compare_str);
    if (!array) return NULL;

    printf("Введите элементы:\n");
    char s[128];
    for (int i = 0; i < size; i++) {
        printf("%d-й элемент: ", i);
        scanf("%s", s);
        char* str = strdup(s);
        if (!str) {
            printf("Ошибка выделения памяти\n");
            free_array(array);
            return NULL;
        }
        array->data[i] = str;
        array->size++;
    }

    return array;
}