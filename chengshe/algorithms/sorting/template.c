/*
includes all functions to generate random ints
and print them out
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANDMAX 100 // ceiling of rand int

int *randArray(size_t nums)
{
    srand(time(NULL));
    int *arr = (int *)malloc(nums * sizeof(int));
    for (int i = 0; i < nums; i++)
    {
        arr[i] = rand() % RANDMAX;
    }
    return arr;
}

void printArray(int arr[], int nums)
{
    printf("{");
    for (int i = 0; i < nums - 1; i++)
        printf("%d, ", arr[i]);
    printf("%d}\n", arr[nums - 1]);
}

void swap(int arr[], int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}
/********** END OF SUPPORTING FUNCTIONS ***********/
int main()
{
    const int maxValue = 100;
    int n; // nums of array
    printf("Enter how many values to sort:");
    scanf("%d", &n);
    int *arr = randArray(n);
    printArray(arr, n);

    // sort(arr, n);

    printArray(arr, n);
    free(arr);

    return 0;
}