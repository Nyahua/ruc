#include <stdio.h>
#include <string.h>

void f(char s[], int i, int j)
{
    if (j > i)
    {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
        f(s, i + 1, j - 1);
    }
    else
        return;
}

int main()
{
    char a[] = "abcdefg";
    f(a, 0, 4);
    printf("%s\n", a);
    return 0;
}