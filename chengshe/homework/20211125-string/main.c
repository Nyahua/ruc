#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int replaceStr(char A[], const char B[], const char C[])
{
    //补充代码，完成此函数

    // to find starting point of B in A
    char *pB = strstr(A, B);
    if (pB) // found or not
    {

        char tail[110];               // temp string for tail
        strcpy(tail, pB + strlen(B)); // copy from found + len(B)

        strcpy(pB, C);                // copy C from postion B
        strcpy(pB + strlen(C), tail); // copy tail from postion +C
        return 1;
    }
    else

        return 0;
}

int main()
{
    char str1[110], str2[110], str3[110];
    int nRes;

    gets(str1);
    gets(str2);
    gets(str3);

    nRes = replaceStr(str1, str2, str3);
    printf("%d\n", nRes);
    printf("%s\n", str1);

    return 0;
}