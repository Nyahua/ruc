#include <stdio.h>
#include <string.h>

int main()
{
    char str[] ="don��t";

    for (int i =0; i<strlen(str); i++)
        printf("%d: %c %d\n", i, str[i], str[i]);

    return 0;
}