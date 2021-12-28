#include <stdio.h>
#include <string.h>
int main()
{
    char str[501] = "abcde";
    /* 未初始化指针 */
    char *pch;
    printf("pch without initialized: %p, pch==NULL: %d\n\n", pch, pch == NULL);
   
    /* 未查找到字符串，返回NULL */
    pch = strstr(str, "fg");
    printf("strstr not found: pch: %p, pch == NULL: %d\n", pch, pch == NULL);
    if (pch)
        puts("if(pch) is true");
    else
        puts("if(pch) is false\n");

    /* 查找到字符串，返回找到位置 */
    pch = strstr(str, "ab");
    printf("strstr found: pch: %p, pch == NULL %d\n", pch, pch == NULL);
    if (pch)
        puts("if(pch) is true\n");
    else
        puts("if(pch) is false\n");

    /* 字符串指针，指针指向的字符，字符对应的ascall码 */
    while(*pch)
    {
        printf("(%p: %c(%d)\n",pch, *pch, *pch);
        pch++;
    }
     printf("(%p: %c(%d)\n",pch, *pch, *pch);
}