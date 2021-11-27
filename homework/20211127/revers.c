#include <stdio.h>

void reverse(char a[], int i, int j)
{
    if (i < j)
    {
        char ch = a[i];
        a[i] = a[j];
        a[j] = ch;
        reverse(a, i + 1, j - 1);
    }
    else
        return;
}

int main()
{
    char str[] = "abcde";
    reverse(str, 0, 4);
    puts(str);
}