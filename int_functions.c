#include "int_functions.h" 

void print_integers(Array* array) {
    printf("(%2d): ", array->size); 
    for (int i = 0; i < array->size; i++) {
        printf("%4d ", *((int*)array->data[i])); 
    }
    printf("\n");
}

int compare_int(void* p1, void* p2) {
    int a = *((int*)p1);
    int b = *((int*)p2);
    return a - b;
}


void generate_int_data(Array* array, int min, int max, int size) {

    for (int i = 0; i < array->size; i++) {
        free(array->data[i]);
    }
    free(array->data);

    array->data = (void**)malloc(sizeof(void*) * size);
    array->capacity = size;
    array->size = 0;

    for (int i = 0; i < size; i++) {
        int x = rand() % (max - min + 1) + min;
        int* element = (int*)malloc(sizeof(int));
        *element = x;
        array->data[i] = element;
        array->size++;
    }
}

int is_even(void* p) {
    int x = *((int*)p);
    return x % 2 == 0;
}


void* cube(void* p) {
    int x = *((int*)p);
    x = x * x * x;
    int* new_x = (int*)malloc(sizeof(int)); 
    if (new_x == NULL) {
        return NULL;
    }
    *new_x = x; 
    return (void*)new_x;
}



Array* input_int_array() {
    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);

    if (size <= 0) return NULL;
    
    Array* array = init_array(sizeof(int), size, print_integers, compare_int);
    if (!array) return NULL;

    printf("Введите элементы:\n");
    int x;
    for (int i = 0; i < size; i++) {
        printf("%d-й элемент: ", i);
        if (scanf("%d", &x) != 1) {
            printf("Ошибка при вводе числа %d. Попробуйте снова.\n", i);
            i--;
            continue;
        }
        push_array(array, &x);
    }

    return array;
}