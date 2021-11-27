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

// 把数组第一个值作为轴（pivot），
// 把比自己小的和大的数分成左右两区
// 数组作为参数被重新分区，并返回轴的新位置。
int split(int arr[], int low, int high)
{
    // 拔出第一个萝卜，产生第一个坑
    // 拔出的萝卜放在pivot这个筐里
    int pivot = arr[low];
    while (low < high)
    {
        //  从后往前找小于piovt的数填前面的坑
        while ((arr[high] >= pivot) && (low < high))
            high--;
        arr[low] = arr[high];

        //  从前往后找大于pivot的数填前面的坑
        while (arr[low] <= pivot && (low < high))
            low++;
        arr[high] = arr[low];
    }

    // 坑的左右分别是比萝卜小和大的数
    // 把拔出的萝卜放回坑里，并返回坑的位置
    arr[low] = pivot;
    return low;
}

// 对分出的左右分区递归分区动作，
// 直到被分区的数组只有1个数
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = split(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
    else
        return;
}

int main()
{
    const int maxValue = 100;
    int n; // nums of array
    printf("Enter how many values to sort:");
    scanf("%d", &n);
    int *arr = randArray(n);
    printArray(arr, n);

    quicksort(arr, 0, n - 1);

    printArray(arr, n);
    free(arr);

    return 0;
}