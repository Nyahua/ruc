#include <stdio.h>

void swap(int *i, int *j)
{
    int t = *i;
    *i = *j;
    *j = t;
}

int main()
{
    int a = 2, b = 3;
    printf("a=%d, b=%d\n", a, b);
    swap(&a, &b);
    printf("a=%d, b=%d\n", a, b);

    return 0;
}