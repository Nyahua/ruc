#include <stdio.h>
#include <math.h>
#include <string.h>

long long mypower(int x, int y)
{
    long long result = 1;
    for (int i = 0; i < y ; i++)
    {
        result = result * x;
    }
    return result;
}
int main()
{
    int first, k, i, j, b;
    scanf("%x %d", &first, &k);
    int z = 16 - first;
    int c = first;
    long long sum = 0;
    for (i = 0; i < z; i++)
    {
        first = c + i;
        for (j = 0; j < k; j++)
        {
            if ((first + j) > 15)
                b = first + j - 16;
            else
                b = first + j;
            sum = sum + b * mypower(16, k - j - 1);
        }
    }
    printf("%lld", sum);

    return 0;
}