#include <stdio.h>
#include <string.h>
#include <stdlib.h> // for atoi
int year, month, day;
char str1[10], str2[10], str3[10];
char string[50]; // the input string

int charType(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    else if (c >= 'A' & c <= 'z')
        return 0;
    else
        return -1;
}

int convertMonth(char *strMonth)
{
    char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for (int i = 0; i < 12; i++)
        if (strcmp(strMonth, months[i]) == 0)
            return i + 1;
}

void break3(char string[100])
{
    char *pch = string;

    strcpy(str1, string);
    // to the end of first substring
    while (charType(*pch) > -1)
        pch++;
    str1[pch - string] = 0;

    // skip first deliminators
    while (charType(*pch) == -1)
        pch++;

    strcpy(str2, pch);
    // find the end of second substring
    char *pch2 = pch;
    while (charType(*pch) > -1)
        pch++;
    str2[pch - pch2] = 0;

    // skip 2nd deliminators
    while (charType(*pch) == -1)
        pch++;
    strcpy(str3, pch);
}

int main()
{
    strcpy(string, "1.3.2018");
    break3(string);
    if (charType(str1[0]) == 0) // 第一段字符串为字母格式
    {
        month = convertMonth(str1);
        year = atoi(str3);
        day = atoi(str2);
    }
    else if (strlen(str1) == 4) // 第一段字符串长度为4
    {
        year = atoi(str1);
        month = atoi(str2);
        day = atoi(str3);
    }

    else if (strlen(str3) == 4) // 第3段字符串长度为4
    {
        year = atoi(str3);
        month = atoi(str1);
        day = atoi(str2);
    }

    printf("%s|%s|%s\n", str1, str2, str3);
    printf("%04d%02d%02d\n", year, month, day);

    return 0;
}