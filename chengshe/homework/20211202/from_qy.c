#include <stdio.h>
// int a[1900];
int a[] = {2, 3, 5, 1, 4};
int i, j, k;
int m, n;
int c;
int compare = 0;
void px(int a[])
{
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                k = a[j];
                a[j] = a[j + 1];
                a[j + 1] = k;
            }
        }
    }
}
int find(int left, int right, int m)
{
    if (left > right)
    {
        return -1;
    }
    c = (left + right) / 2;
    if (a[c] == m)
    {
        compare++;
        printf("%d\n", compare);
        return c;
    }
    else if (a[c] > m)
    {
        compare++;
        return find(left, c - 1, m);
    }
    else
    {
        compare++;
        return find(c + 1, right, m);
    }
}
int main()
{
    // scanf("%d",&n);
    // scanf("\n");
    n = 5;
    scanf("%d", &m);

    px(a);
    for (i = 0; i < n; i++)
        printf("%d, ", a[i]);
    printf("\n");
    int pos = find(1, n, m);

    printf("compare: %d\n", compare);
    printf("position: %d\n", pos);
    //  for(i=1;i<=n;i++)
    //
    //	{
    //		printf("%d ",a[i]);
    //	}
    //	printf("%d\n%d\n",find(1,n,m),compare);
    return 0;
}