#include <stdio.h>
#include <string.h>

int charinstr(char ch, char str[])
{
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == ch)
            return i;
    return -1;
}

int strinstr(char str1[], char str2[])
{
    char checkstr[220];
    strcpy(checkstr, str1);
    for (int i = 0; i < strlen(str1); i++)
    {
        int loc = charinstr(str2[i], checkstr);
        printf("%s[%d] found!\n", checkstr, i);
        if (loc > -1)
            strcpy(checkstr + loc, checkstr + loc + 1);
        else
            return 0;
    }
    return 1;
}

int main()
{
    char str1[] = "abc";
    char str2[] = "bacd";
    printf("%d\n", strinstr(str1, str2));
}