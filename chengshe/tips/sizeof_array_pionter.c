#include <stdio.h>
#include <stdlib.h>

int main() {
    
    printf("sizeof int %zu\n", sizeof(int));
    // size of a int is 4

    int arr[] = {1, 2, 3, 4, 5};
    printf("size of arr is %zu\n", sizeof(arr));
    // size of this array is 4 * 5 = 20

    int *p = malloc(5 * sizeof(int));
    int i = 0;
    int arrLength = sizeof(arr) / sizeof(int);
    for(;i < arrLength; i++) {
        p[i] = arr[i];
    }
    printf("size of pointer is %zu\n", sizeof(p));
    // size of a pointer is 8

    free(p); 
    return 0;
}