#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char arrString[][20] = {
    "Zhang San",
    "Li Si",
    "Wang Wi",
    "Zhao Liu",
    "Wang Ermazi"};

int comp(void *p1, void *p2)
{
    char *x = *(char *)p1;
    char *y = *(char *)p2;
    return strcmp(x, y);
}

int main()
{
    qsort(arrString, 5, sizeof(arrString[0]), comp);
    for (int i = 0; i<5; i++)
        printf("%s\n", arrString[i]);
}