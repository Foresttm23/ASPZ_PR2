#include <stdio.h>

void increase_stack_size() {
    int arr1[1000];
    int arr2[2000];
    int arr3[3000];

    printf("\n\nTop arr1: %p\n", &arr1);
    printf("Top arr2: %p\n", &arr2);
    printf("Top arr3: %p\n", &arr3);
}

int global_var;

int main() {
    int local_arr;
    static int static_arr;
    
    printf("Top: %p\n", &local_arr);
    printf("Data: %p\n", &global_var);
    printf("BSS: %p\n", &static_arr);

    increase_stack_size();

    return 0;
}
