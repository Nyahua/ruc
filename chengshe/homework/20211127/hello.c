// strstr, strcpy, strcat
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[] = "Hello world!";
    char str2[] = "world";
    char str3[] = "baby";

    printf("str1 adress: %p\n", str1);

    char *pch = strstr(str1, str2);
    printf("searched: %s\n", pch);
    printf("pch adress: %p\n", pch);
    printf("pch to str: %li\n", pch - str1);

    char tail[200];
    strcpy(tail, pch + strlen(str2));
    printf("tail: %s\n", tail);

    strcpy(pch, str3);
    printf("str1: %s\n", str1);
    strcat(str1, tail);
    // strcpy(pch +strlen(str3), tail);
    printf("str1: %s\n", str1);

    return 0;
}