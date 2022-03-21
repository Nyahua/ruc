#include <stdio.h>

// 找到字符ch在字符串str中的位置。
// 循环字符字符串，找到字符，返回当前位置。
int strIndex(char ch, char str[])
{
    int idx = 0;
    while (str[idx]) // while not eof string '\0'==0==false
    {
        if (ch == str[idx]) // search the ch in string
        {
            return idx;
        }
        idx++;
    }
    // ch not found
    return -1;
}

// 比较两个字符的大小，根据两个字符的位置，
// 如果第一字符位置在前返回1，在后-1，相等0。
int charCompare(char ch1, char ch2, char strOrder[])
{
    if (ch1 == ch2) // same chars
    {
        return 0;
    }

    int idx1 = strIndex(ch1, strOrder);
    int idx2 = strIndex(ch2, strOrder);
    if (idx1 < idx2)
    {
        return 1;
    }
    if (idx1 > idx2) // ch2 before ch1
    {
        return -1;
    }
}

// 根据strOrder比较字符串大小。
// 从位置零开始比较两个字符串中的每个字符，遇到第一个不同字符时返回字符比较的大小。
// 如果到了某一字符串的结尾，先到哪个字符串结尾，哪个字符串排前面（1）。
int strCompare(char str1[], char str2[], char strOrder[])
{
    int idx = 0;
    while (str1[idx] && str2[idx]) // while both not eof
    {
        if (str1[idx] == str2[idx]) // continue to next when chars are equal
        {
            idx++;
        }
        else // compare chars when not equal
        {
            return charCompare(str1[idx], str2[idx], strOrder);
        }
    }
    // you get here because one of the string gets end
    if (str1[idx] == '\0')
    {
        if (str2[idx] == '\0') // both get ends
        {
            return 0;
        }
        else // only str1 gets end 
        {
            return 1;
        }
    }
    else // only str2 gets end
    {
        return -1;
    }
}

int main()
{
    char strOrder[] = "ACGT";
    printf("%d\n", strCompare("ACTG", "ACGT", strOrder));

    return 0;
}
