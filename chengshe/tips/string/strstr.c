// 如何做一个字符串中找到多个相同的字符串
#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "home, sweet home, my sweet home!";
    char strFind[] = "home";
    char *p1 = str, *p2; // p1指向str

    int count = 0, pos = 0;
    p2 = strstr(p1, strFind); //在p1(str)中找到第一个strFind
    while (p2)                // 找不到返回null，就是false
    {
        count++;        // 找到数量加一
        pos += p2 - p1; //从找到位置到开始招的位置差
        printf("found %d: at: %li\n", count, pos);
        p1 = p2 + strlen(strFind); // 指针p1定位到找到字符位置的后面
        p2 = strstr(p1, strFind);  // 继续找
    }
}