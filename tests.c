#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "DynamicArray.h"
#include "int_functions.h"
#include "str_functions.h"

#ifndef RESET_ON_FAIL
#define RESET_ON_FAIL 0
#endif

#ifndef VERBOSE_PASS
#define VERBOSE_PASS 1
#endif

#define ASSERT1(ast, msg) \
do { \
    if (ast) { \
        if (VERBOSE_PASS) printf("TEST %s PASSED\n", msg); \
        else puts("."); \
    } \
    else { \
        fprintf(stderr, "TEST %s FAILED (Line %d: %s)\n", msg, __LINE__, #ast); \
        if (RESET_ON_FAIL) exit(1); \
    } \
} while (0)

void test_init_int_array() {
    Array* arr = init_array(sizeof(int), 5, print_integers, compare_int);
    ASSERT1(arr != NULL, "init_int_array: non-NULL return");
    ASSERT1(arr->capacity == 5, "init_int_array: correct capacity");
    ASSERT1(arr->size == 0, "init_int_array: initial count is 0");
    free_array(arr);
}

void test_push_int_array() {
    Array* arr = init_array(sizeof(int), 3, print_integers, compare_int);
    int x = 42, y = 100;

    push_array(arr, &x);
    ASSERT1(arr->size == 1, "push_int_array: count increments");
    ASSERT1(*(int*)arr->data[0] == 42, "push_int_array: correct value stored");

    push_array(arr, &y);
    ASSERT1(*(int*)arr->data[1] == 100, "push_int_array: second value correct");
    
    free_array(arr);
}

void test_sort_int_array() {
    Array* arr = init_array(sizeof(int), 3, print_integers, compare_int);
    int values[] = {30, 10, 20};
    for (int i = 0; i < 3; i++) push_array(arr, &values[i]);

    sort_array(arr);
    ASSERT1(*(int*)arr->data[0] == 10, "sort_int_array: first element");
    ASSERT1(*(int*)arr->data[1] == 20, "sort_int_array: second element");
    ASSERT1(*(int*)arr->data[2] == 30, "sort_int_array: third element");

    free_array(arr);
}


void test_compare_str() {
    char *s1 = "apple";
    char *s2 = "banana";
    char *s3 = "apple";

    ASSERT1(compare_str(&s1, &s2) < 0, "compare_str: s1 < s2");
    ASSERT1(compare_str(&s2, &s1) > 0, "compare_str: s2 > s1");
    ASSERT1(compare_str(&s1, &s3) == 0, "compare_str: s1 == s3");
}

void test_is_all_alphas() {
    char *valid = "Hello";
    char *invalid = "H3llo!";

    ASSERT1(is_all_alphas(valid) == 1, "is_all_alphas: valid string");
    ASSERT1(is_all_alphas(invalid) == 0, "is_all_alphas: invalid string");
}

void test_to_uppercase() {
    char *input = "aBc123";
    char *expected = "ABC123";
    char *result = (char *)to_uppercase(input);

    ASSERT1(strcmp(result, expected) == 0, "to_uppercase: correct conversion");
    free(result);
}

void test_str_array_operations() {
    Array* arr = init_array(sizeof(char*), 3, print_strings, compare_str);
    char *strings[] = {"hello", "world", "test"};
    
    for (int i = 0; i < 3; i++) {
        push_array(arr, &strings[i]);
    }
    
    ASSERT1(arr->size == 3, "str_array_operations: correct count");
    ASSERT1(strcmp(*(char**)arr->data[0], "hello") == 0, "str_array_operations: first element");
    
    free_array(arr);
}


int main() {
    printf("=== Running Integer Array Tests ===\n");
    test_init_int_array();
    test_push_int_array();
    test_sort_int_array();

    printf("\n=== Running String Array Tests ===\n");
    test_compare_str();
    test_is_all_alphas();
    test_to_uppercase();
    test_str_array_operations();

    printf("\nAll automated tests completed.\n");
    return 0;
}