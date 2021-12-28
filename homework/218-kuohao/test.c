#include <stdio.h>
#include <string.h>

int main()
{

    // char str[501] = "(){()}";
    char str[501] = "abcabc";

    char *pch = strstr(str, "ab");
    puts(pch);
    puts(pch + 2);
    char new[501];

    strcpy(new, pch + 2);
    // while (*pch)
    // {
    //     *pch = *(pch + 2);
    //     pch++;
    // }

    puts(new);
    puts(memmove(str, str+2, sizeof(str+2)));
}
