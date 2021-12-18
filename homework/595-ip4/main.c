#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isnotip(char ip[]) // 判断截取的ip是否合法，如果不合法返回1
{
    if (strlen(ip) > 1 && ip[0] == '0') // 以0开头的正整数
        return 1;
    if (atoi(ip) > 255) //字符串转为整数 atol()转长整数 atoll:转long long, atof: 转浮点
        return 1;
    return 0;
}

int main()
{
    char input[13]; // 输入的字符串，不超过12个长度
    scanf("%s", &input);
    int len = strlen(input); // 字符串长度
    // 4段网址:
    char ip1[20], ip2[20], ip3[20], ip4[20]; 
    // 尽管每段长度都小于4，但要先拷贝，后截取，所以预留了足够多长度
    
    int len1, len2, len3;                    // 前面三个ip的长度
    for (int len1 = 1; len1 <= 3; len1++)    // ip1从1到3长度循环
    {
        if (len < len1) // 如果输入的字符串长度不足则退出此循环
            continue;
        strcpy(ip1, input); // 把input拷入第一段网址
        ip1[len1] = 0;      //  ip1在长度位置截断
        if (isnotip(ip1)) // 如果ip1不合法则跳过这个ip
            continue;
        // printf("len1:%d ip1:%s, ", len1, ip1); // debug
        for (int len2 = 1; len2 <= 3; len2++) // 循环第二个网段
        {
            if (len < len1 + len2) 
                continue;
            strcpy(ip2, input + len1); // 从第一段长度后开始拷贝
            ip2[len2] = 0; // 从拷贝后的长度len2开始截断
            if (isnotip(ip2))
                continue;
            for (int len3 = 1; len3 <= 3; len3++)
            {
                if (len < len1 + len2 + len3 + 1)
                    continue;
                strcpy(ip3, input + len1 + len2);
                ip3[len3] = 0;
                if (isnotip(ip3))
                    continue;
                strcpy(ip4, input + len1 + len2 + len3);
                if (isnotip(ip4))
                    continue;
                else
                    printf("%s.%s.%s.%s\n", ip1, ip2, ip3, ip4);
            }
        }
    }

    return 0;
}