#include <stdio.h>
#include <string.h>
char str[501];

/* 判断字符是否是括号 1/0 */
int isKuohao(char c)
{
    char kuohao[] = "(){}";
    for (int i = 0; i < strlen(kuohao); i++)
        if (c == kuohao[i])
            return 1;
    return 0;
}

/* 除去字符串中所有非括号 */
void rmOthers(char s[])
{
    int count = 0;
    for (int i = 0; i < strlen(s); i++)
        if (isKuohao(s[i]))
        {
            s[count] = s[i];
            count++;
        }
    s[count] = 0;
}

/* 除去字符串中所有在一起成对的大括号 */
void rmBig(char s[])
{
    char *pch = strstr(s, "{}"); // 找到括号组所在位置
    if (pch)
        memmove(pch, pch + 2, sizeof(pch + 2)); 
}

/* 除去字符串中所有在一起成对的小括号 */
void rmSmall(char s[])
{
    char *pch = strstr(s, "()");
    if (pch)
        memmove(pch, pch + 2, strlen(s));
        // while (*pch)
        // {
        //     *pch = *(pch +2);
        //     pch++;
        // }
}
int main()
{
    int n;
    scanf("%d", &n);
    getchar();

    char inputs[n][501];
    for (int i = 0; i < n; i++)
        gets(inputs[i]);

    for (int i = 0; i < n; i++)
    {
        char *str = inputs[i];
        rmOthers(str);
        // puts(str);
        int len, newlen; // 用来保存字符串的长度和去掉字符串的长度
        while (1)
        {
            len = strlen(str);
            rmSmall(str);
            // puts(str);
            rmBig(str);
            // puts(str);
            newlen = strlen(str);
            if (newlen == len) // 长度不变，表示不能去除字符组了，跳出循环
                break;
            else
                len = newlen;
        }
        if (newlen)
            puts("false");
        else
            puts("true");
    }
}
