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

int main()
{
    const int maxValue = 100;
    int n; // nums of array
    scanf("Enter how many values to sort:");
    scanf("%d", &n);
    srand(time(NULL));
    int *arr = randArray(n, maxValue);
    printArray(arr, n);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr, i, j);
            }
        }
    }

    printArray(arr, n);
    free(arr);
    
    return 0;
}