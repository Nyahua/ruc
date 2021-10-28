#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("sizeof int %zu\n", sizeof(int));

    int arr[] = {1, 2, 3, 4, 5};
    printf("size of arr is %zu\n", sizeof(arr));

    int *p = malloc(5 * sizeof(int));
    int i = 0;
    int arrLength = sizeof(arr) / sizeof(int);
    for(;i < arrLength; i++) {
        p[i] = arr[i];
    }
    printf("size of pointer is %zu\n", sizeof(p));
    return 0;
}