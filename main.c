#include <stdio.h>
#include <stdlib.h>
#include "DynamicArray.h"
#include "int_functions.h"
#include "str_functions.h"


void UI() {
    printf("\n________________________________________________________________________________\n");
    printf("1. Выберите тип данных. \n");
    printf("2. Выберите операцию. \n");
    printf("0. Выйти.\n");
    printf("________________________________________________________________________________\n");
}

void choices() {

    int choice, choice1, choice2;

    while (1) {
        UI();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("________________________________________________________________________________\n");
                printf("1. Целые числа.\n");
                printf("2. Строки.\n");
                printf("________________________________________________________________________________\n");
                scanf("%d", &choice1);
                Array* array = NULL;

                int (*where_f)(void*) = NULL;
                void* (*map_f)(void*) = NULL;

                if (choice1 == 1){
                    array = input_int_array();
                    where_f = is_even;
                    map_f = cube;
                }

                else if (choice1 == 2) {
                    array = input_str_array();
                    where_f = is_all_alphas;
                    map_f = to_uppercase;
                }
                break;

            case 2:
                printf("________________________________________________________________________________\n");
                printf("1. Сортировка. \n");
                printf("2. Map. \n");
                printf("3. Where. \n");
                printf("4. Конкатенация.\n");
                printf("________________________________________________________________________________\n");
                scanf("%d", &choice2);

                if (array == NULL || array->size == 0) {
                    printf("Сначала заполните массив.\n");
                    break;            
                }

                if (choice2 == 1){
                    printf("До сортировки:\n");
                    print_array(array);

                    sort_array(array);

                    printf("После сортировки:\n");
                    print_array(array);
                }
                if (choice2 == 2) {
                    printf("До map:\n");
                    print_array(array);

                    Array* new_array = map(array, map_f);

                    printf("После map:\n");
                    print_array(new_array);

                    free_array(new_array);
                }

                if (choice2 == 3) {
                    printf("До where:\n");
                    print_array(array);

                    Array* new_array = where(array, where_f);

                    printf("После where:\n");
                    print_array(new_array);

                    free_array(new_array); 
                }

                if (choice2 == 4){
                    printf("Изначальный массив:\n");
                    print_array(array);

                    Array* other_array = NULL;

                    if (choice1 == 1) {
                        other_array = input_int_array();
                    }
                    else if (choice1 == 2) {
                        other_array = input_str_array();
                    }

                    printf("Второй массив:\n");
                    print_array(other_array);


                    Array* result = concatenation(array, other_array);

                    printf("Результат конкатенации:\n");
                    print_array(result);

                    free(other_array);
                    free(result);
                }

                free_array(array);

                break;

            case 0:
                exit(0);
                break;

        }
    }


}

int main(){
    choices();

}
