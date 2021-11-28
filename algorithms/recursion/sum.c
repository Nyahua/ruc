#include <stdio.h>

int sum_for(int a[], int n)
{
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        t += a[i];
    }
    return t;
}

int sum_recursive(int a[], int n)
{
    if (n == 1)
        return a[0];
    else
        return a[0] + sum_recursive(a + 1, n - 1);
}

int main()
{
    int arr[] = {5, 3, 4, 2, 1, 5};
    int n = sizeof(arr) / sizeof(*arr);
    printf("sum of array by for: %d\n", sum_for(arr, n));
    printf("sum of array by for: %d\n", sum_recursive(arr, n));

    return 0;
}