#include <stdio.h>

int main()
{
    int first, k, i;
    scanf("%x %d", &first, &k);
    long long num = 0, total = 0;
    while (first <= 15)
    {
        num = first;
        for (i = 1; i < k; i++)
        {
            num = num * 16;
            if (first + i > 15)
                num += first + i - 16;
            else
                num += first + i;
        }
        total += num;
        first++;
    }
    printf("%lld\n", total);

    return 0;
}