#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *randArray(size_t nums, int maxValue)
{
    srand(time(NULL));
    int *arr = (int *)malloc(nums * sizeof(int));
    for (int i = 0; i < nums; i++)
    {
        arr[i] = rand() % maxValue;
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

int locOfSmallest(int a[], int from, int to)
{
    int j = from;
    for (int i = from; i <= to; i++)
        if (a[i] < a[j])
            j = i;
    return j;
}

void selectionSort(int a[], int n)
{
    int i = 0;
    while (i < n - 1)
    {
        int j = locOfSmallest(a, i, n - 1);
        swap(a, i, j);
        i++;
    }
}

int main()
{
    const int maxValue = 100;
    int n; // nums of array
    printf("Enter how many values to sort:");
    scanf("%d", &n);
    int *arr = randArray(n, maxValue);
    printArray(arr, n);

    selectionSort(arr, n);

    printArray(arr, n);
    free(arr);

    return 0;
}