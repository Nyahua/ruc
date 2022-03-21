#include <stdio.h>
#include <math.h>

int MAX = 0;
int TREE[100][100];

long long powlong(int n)
{
    int i;
    long long res = 1;
    for (i = 1; i <= n; i++)
        res = 2 * res;
    return res;
}
int main()
{
    int n = 50;
    printf("%d: %li", n, powlong(n));
    // int n;
    // scanf("%d", &n);
    // int i, j;

    // for (i = 0; i < n; i++)
    //     for (j = 0; j <= i; j++)
    //         scanf("%d", &TREE[i][j]);

    // int arr[n];
    // dropTree(arr, 0, 0, n);
    // printf("%d\n", MAX);
    return 0;
}