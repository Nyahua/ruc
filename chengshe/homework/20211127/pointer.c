/* 指针的基本概念 */

#include <stdio.h>

int main()
{
    int i = 123;
    printf("addr of i: %p\n", &i);
    printf("value of i: %d\n", i);

    int *p;
    printf("addr of p: %p\n", &p);
    printf("value in p: %p\n", p);

    p = &i;
    printf("addr of p: %p\n", &p);
    printf("value of p: %p\n", p);
    printf("value of p point to: %d\n", *p);

    return 0;
}