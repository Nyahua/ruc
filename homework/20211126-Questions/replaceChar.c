#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "abcde";
    printf("%d\n", s[5]); // \0
    printf("%d\n", 'a' - 'A'); //32

    for (int i = 0; i < strlen(s); i++)
        s[i] = s[i] - 32;

    printf("%s\n", s); // ABCED
    
    return 0;
}