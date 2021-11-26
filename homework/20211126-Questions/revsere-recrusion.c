#include <stdio.h>
#include <string.h>

void f(char s[], int i, int j)
{
    if (strlen(s) == 1)
        s[0] = s[0];
    else
    {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
        f(s, i + 1, j - 1);
    }
}

int main()
{
    char a[] = "abcdefg";
    f(a, 0, 4);
    for (int i = 0; i < strlen(a); i++)
        printf("%d, ", a[i]);
    printf("\n");
    return 0;
}