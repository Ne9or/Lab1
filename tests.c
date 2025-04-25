
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "DynamicArray.h"
// #include "int_functions.h"
// #include "str_functions.h"

// void test_init_array() {
//     Array* array = create_dynamic_array(sizeof(int), print_integers, compare_int);
//     if (array == NULL) {
//         printf("ERROR: init_array failed\n");
//         return;
//     } else {
//         printf("test_init_array passed\n");
//     }
//     free_array(array);
// }

// void test_push_array() {
//     Array* array = create_dynamic_array(sizeof(int), print_integers, compare_int);
//     int x = 42;
//     push_array(array, &x);
//     if (array->size != 1 || *((int*)array->data[0]) != 42) {
//         printf("ERROR: push_array failed\n");
//     } else {
//         printf("test_push_array passed\n");
//     }
//     free_array(array);
    
// }

// void test_sort_array() {
//     Array* array = create_dynamic_array(sizeof(int), print_integers, compare_int);
//     int arr[] = {5, 2, 8, 1, 3};
//     for (int i = 0; i < 5; i++) {
//         push_array(array, &arr[i]);
//     }
//     sort_array(array);
//     int expected[] = {1, 2, 3, 5, 8};
//     for (int i = 0; i < 5; i++) {
//         if (*((int*)array->data[i]) != expected[i]) {
//             printf("ERROR: sort_array failed\n");
//             break;
//         }
//     }
//     free_array(array);
//     printf("test_sort_array passed\n");
// }

// void test_concatenation() {
//     Array* array1 = create_dynamic_array(sizeof(int), print_integers, compare_int);
//     Array* array2 = create_dynamic_array(sizeof(int), print_integers, compare_int);
//     int arr1[] = {1, 2, 3};
//     int arr2[] = {4, 5, 6};
//     for (int i = 0; i < 3; i++) {
//         push_array(array1, &arr1[i]);
//         push_array(array2, &arr2[i]);
//     }   
//     Array* result = concatenation(array1, array2);
//     int expected[] = {1, 2, 3, 4, 5, 6};
//     for (int i = 0; i < 6; i++) {
//         if (*((int*)result->data[i]) != expected[i]) {
//             printf("ERROR: concatenation failed\n");
//             break;
//         }
//     }
//     free_array(array1);
//     free_array(array2);
//     free_array(result);
//     printf("test_concatenation passed\n");
// }

// void test_where() {
//     Array* array = create_dynamic_array(sizeof(int), print_integers, compare_int);
//     int arr[] = {1, 2, 3, 4, 5, 6};
//     for (int i = 0; i < 6; i++) {
//         push_array(array, &arr[i]);
//     }
//     Array* result = where(array, is_even);
//     int expected[] = {2, 4, 6};
//     if (result->size != 3) {
//         printf("ERROR: where failed\n");
//     } else {
//         for (int i = 0; i < 3; i++) {
//             if (*((int*)result->data[i]) != expected[i]) {
//                 printf("ERROR: where failed\n");
//                 break;
//             }
//         }
//     }
//     free_array(array);
//     free_array(result);
//     printf("test_where passed\n");
// }

// void test_map() {
//     Array* array = create_dynamic_array(sizeof(int), print_integers, compare_int);
//     int arr[] = {1, 2, 3};
//     for (int i = 0; i < 3; i++) {
//         push_array(array, &arr[i]);
//     }
//     Array* result = map(array, cube);
//     int expected[] = {1, 8, 27};
//     for (int i = 0; i < 3; i++) {
//         if (*((int*)result->data[i]) != expected[i]) {
//             printf("ERROR: map failed\n");
//             break;
//         }
//     }
//     free_array(array);
//     free_array(result);
//     printf("test_map passed\n");
// }

// void test_str_functions() {
//     Array* array = create_dynamic_array(256, print_strings, compare_str);
//     char* str1 = "hello";
//     char* str2 = "world";
//     push_array(array, str1);
//     push_array(array, str2);

//     Array* result = where(array, is_all_alphas);
//     if (result->size != 2) {
//         printf("ERROR: is_all_alphas failed\n");
//     } else {
//         printf("test_is_all_alphas passed\n");
//     }

//     result = map(array, to_uppercase);
//     char* expected1 = "HELLO";
//     char* expected2 = "WORLD";
//     if (strcmp((char*)result->data[0], expected1) != 0 || strcmp((char*)result->data[1], expected2) != 0) {
//         printf("ERROR: to_uppercase failed\n");
//     } else {
//         printf("test_to_uppercase passed\n");
//     }

//     free_array(array);
//     free_array(result);
//     printf("test_str_functions passed\n");
// }

