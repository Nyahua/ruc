#include <stdio.h>

void dropTree(int arr[], int fromPos, int fromLevel, int n)
{
    int i;
    if (fromLevel == n - 1)
    {
        for (i = 0; i < n; i++)
            printf("%d, ", arr[i]);
        puts("");
        return;
    }

    arr[fromLevel] = fromPos;
    arr[fromLevel + 1] = fromPos;
    dropTree(arr, fromPos, fromLevel + 1, n);
    arr[fromLevel + 1] = fromPos + 1;
    dropTree(arr, fromPos + 1, fromLevel + 1, n);
}

int main()
{
    int n = 4;
    int arr[n];
    dropTree(arr, 0, 0, n);
    return 0;
}