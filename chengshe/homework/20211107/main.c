#include <stdio.h>
int abs(int c)
{
    if (c >= 0)
    {
        return c;
    }
    else
    {
        return -c;
    }
}

int main()
{
    int i, j, n;
    long sum = 0;
    long min, temp;
    scanf("%d", &n);
    long arr[n];
    long arrmin[n];

    for (i = 0; i < n; i++)
    {
        scanf("%ld", &arr[i]);
        min = arr[i];
        for (j = 0; j < i; j++)
        {
            temp = abs(arr[j] - arr[i]);
            if (temp < min)
            {
                min = temp;
            }
        }
        arrmin[i] = min;
    }
    for (i = 0; i < n; i++)
    {
        printf("%ld +", arrmin[i]);
    }
        printf("\n");

    return 0;
}