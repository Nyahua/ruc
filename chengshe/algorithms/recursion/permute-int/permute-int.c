// 递归法排列
// 参见：https://www.geeksforgeeks.org/c-program-to-print-all-permutations-of-a-given-string/

// C program to print all permutations with duplicates allowed
#include <stdio.h>

void swap(int arr[], int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

// arr[n] 从l到r全排列
void permute(int arr[], int l, int r, int n)
{
    if (l == r) // 从左到右每个数都轮了一遍，则打印
    {
        for (int j = 0; j < n; j++)
            printf("%d ", arr[j]);
        puts(""); // 本行数组打印结束，换行
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(arr, l, i);
            permute(arr, l + 1, r, n);
            swap(arr, l, i); // backtrack
        }
    }
}

int main()
{
    int arr[] = {3, 5, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    permute(arr, 0, n - 1, n);
    return 0;
}