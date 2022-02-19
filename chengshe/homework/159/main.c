// 在最后一个找到的字符串前插入另一个字符串的演示

#include <stdio.h>
#include <string.h>
char a[300]; //被操作的
char b[200]; //命令行

/*
find last occurrence of str1 in a[300]
we find from the end of a[300],
if not found, move left one by one
基本思路：把指针指向字符串的最后，然后用strstr查找指针后的字符串
一个一个字符向前挪动，直到找到为止，返回这个指针的位置
*/
char *strLast(char *str1)
{
    int n = strlen(a);
    while (n) // if n not decrease to 0
    {
        char *p = a + n;     // point to the end of sentence
        if (strstr(p, str1)) // if found str2, return
            return p;
        n--; // if not found, move one char left
    }
    return NULL;
}

/*
insert str2 before last str1 in a[300]
找到查找的字符串所在位置后，把这个位置后的字符串保存到temp里；
然后从这个位置替换为要被替换掉字符串，形成新的a[300]
然后把a[300]与temp strcat就可以了。
*/
void strIns(char *str1, char *str2)
{
    char *p = strLast(str1);
    char *temp;
    strcpy(temp, p); // save the tail part to temp
    strcpy(p, str2); // replace with str2 from p
    strcat(a, temp); // concat the tail with new a
}

void strRpl(char *str1, char *str2)
/* 功能：表示在原字符串中用str2替换str1，str1为被替换的子串，
str2为替换的子串，若在原串中有多个str1则应全部替换。
但当替换进去的子串与原串拼接后新出现子串str1时，不用再替换。
*/
{
    char *p = a;
    p = strstr(a, str1); // find fisrt str2
    while (p)            // 当p找到内容时循环，否则返回NULL
    {
        char *temp;
        strcpy(temp, p + strlen(str1));     // save the tail
        strcpy(p, str2);                    // replace all string from p with str2
        strcat(a, temp);                    // concat new a with tail
        p = strstr(p + strlen(str2), str1); // contunue search from tail
    }
}

int main()
{
    strcpy(a, "home, sweet home, my sweet home!");
    char str1[] = "home";
    char *p = strLast(str1);
    printf("last found: %s\n", p);

    strIns(str1, "warm ");
    printf("insert: %s\n", a);

    strRpl(str1, "house");
    printf("replace: %s\n", a);
}