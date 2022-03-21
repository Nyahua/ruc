#include <stdio.h>
#include <string.h>

// 找到字符ch否在str中所在位置，否则返回-1
int charinstr(char ch, char str[])
{
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == ch)
            return i;
    return -1;
}

// str1的排列是否在str2前面n个字符中，n为str1长度
int strinstr(char str1[], char str2[])
{
    char checkstr[220];
    strcpy(checkstr, str1); // 拷贝str1，以后每次找到一个字母，减去这个字母
    for (int i = 0; i < strlen(str1); i++)
    {
        int loc = charinstr(str2[i], checkstr);         // 对str2从第一个到第n个字符进行查找
        if (loc > -1)                                   // 如果这个字符在str2的子集里
            strcpy(checkstr + loc, checkstr + loc + 1); // 中子集里减去这个字符，继续查找下一个
        else
            return 0;
    }
    return 1; // 全部找到返回1
}

char *checkSubstr(char s1[], char s2[])
{
    char *pchar; // 返回字符串需要定义为字符型指针
    for (int i = 0; i < strlen(s2); i++) // 从s2到每一个位置开始看当前字母后面是否与s1排列相同
    {
        if (strinstr(s1, s2 + i))
        {
            pchar = s2 + i; // 如果相同，把当前位置赋给字符指针并返回
            return pchar; // 返回的指针指向s2符合要求的位置后面所有字符串
        }
    }
    return NULL;
}

int main()
{
    char s1[220], s2[220];
    char *pRes = NULL;
    scanf("%s%s", s1, s2);
    pRes = checkSubstr(s1, s2);
    if (pRes == NULL)
        printf("false ");
    else
    {
        pRes[strlen(s1)] = '\0'; // 在需要的长度处截断
        printf("%s", pRes);
    }
    return 0;
}