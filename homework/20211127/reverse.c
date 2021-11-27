// 递归反转字符串

#include <stdio.h>
#include <string.h>

void reverse(char a[], int i, int j)
{
    if (i >= j)
        return;
    else
    {
        char ch = a[i];
        a[i] = a[j];
        a[j] = ch;
        reverse(a, i + 1, j - 1);
    }
}

int main()
{
    char str[] = "abcdef";
    reverse(str, 0, strlen(str)-1);
    puts(str);
}