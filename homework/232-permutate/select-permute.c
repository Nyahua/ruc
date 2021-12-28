// C program to print all permutations with duplicates allowed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n;
char a[510], res[510] = {0}; // 原始待排列字符串与结果字符串
int flag[510] = {0}; // 标记本轮递归是否被使用
int count = 0; 

/* Function to print permutations of string */
void permute(int l) // 从l开始排列字符串
{
    if (l == n)
    {
        count += 1;
        printf("%s\n", res);
        exit(0);
    }
    else
    {
        for (int i = 0; i < n; i++) // 从原始字符串a[n]中逐位排列到res的L位
        {
            if (flag[i] == 0) // 如果本位次字符未被使用
            {
                res[l] = a[i];
                flag[i] = 1;
                permute(l + 1);
                flag[i] = 0;
            }
        }
    }
}

int main()
{
    n = 3;
    strcpy(a, "abc");

    permute(0);
    printf("%d\n", count);
    return 0;
}
