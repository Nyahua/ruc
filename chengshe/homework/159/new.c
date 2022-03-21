#include <stdio.h>
#include <string.h>
char a[200]; //被操作的

int main()
{
    char a[200], b[100];
    gets(a);
    gets(b);

    printf("%s\n", a);
    printf("%s\n", b);
    char cmd, *str1, *str2;
    sscanf(b, "%c %s %s", &cmd, str1, str2);
    printf("%c\n%s\n%s", cmd, str1, str2);

}