/*
includes all functions to generate random ints
and print them out
shorturl.at/ctwyJ
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

// 把数组第一个值作为轴（pivot），
// 把比自己小的和大的数分成左右两区

// 对分出的左右分区递归分区动作，
// 直到被分区的数组只有1个数
void quicksort(int arr[], int n)
{
    if (n < 2)
        return;

    int pivot = arr[0];
    int buffer[n];
    int left = 0;
    int right = n - 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < pivot)
        {
            buffer[left] = arr[i];
            left++;
        }
        else
        {
            buffer[right] = arr[i];
            right--;
        }
    }
    buffer[left] = pivot;
    for (int i = 0; i < n; i++)
        arr[i] = buffer[i];
    quicksort(arr, left);
    quicksort(arr + left + 1, n - left - 1);
}

int main()
{
    const int maxValue = 100;
    int n; // nums of array
    printf("Enter how many values to sort:");
    scanf("%d", &n);
    int *arr = randArray(n);
    printArray(arr, n);

    quicksort(arr, n);

    printArray(arr, n);
    free(arr);

    return 0;
}