#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    long long sum1 = 0, sum2 = 0;
    int input;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input);

        if (input % m == 0)
            sum1 += input;
        else
            sum2 += input;
    }
    if (sum1)
        printf("%lli\n", sum1);
    if (sum2)
        printf("%lli\n", sum2);
}