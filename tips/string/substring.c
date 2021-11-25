#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "This is a simple string";
    char *pch;
    pch = strstr(str, "simple");
    printf("find here: %s\n", pch);
    if (pch != NULL)
        strncpy(pch, "\0", 1);
    puts(str);
    return 0;
}