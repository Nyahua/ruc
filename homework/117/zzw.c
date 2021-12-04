#include <stdio.h>

int MAX = 0;
int TREE[100][100];

void dropTree(int arr[], int fromPos, int fromLevel, int n)
{
    int i;
    if (fromLevel == n - 1)
    {
        int peachs = 0;
        for (i = 0; i < n; i++)
            peachs += TREE[i][arr[i]];
        if (peachs > MAX)
            MAX = peachs;
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
    int n;
    scanf("%d", &n);
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j <= i; j++)
            scanf("%d", &TREE[i][j]);

    int arr[n];
    dropTree(arr, 0, 0, n);
    printf("%d\n", MAX);
    return 0;
}