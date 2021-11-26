#include <stdio.h>

void reverse(int a[100], int i, int j)
{
    int t;
    while (i < j)
    {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
        i++;
        j--;
    }
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    reverse(a[5], 0, 4);
    for (int i = 0; i < 5; i++)
        printf("%d, ", a[i]);
    printf("\n");
    return 0;
}