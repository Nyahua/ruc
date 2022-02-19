#include <stdio.h>
#include <string.h>
int main()
{
    int i, j, k, n;
    scanf("%d", &n);
    getchar();
    char a[60][30];
    char str[30];
    for (i = 0; i < n; i++)
    {
        gets(a[i]);
    }

    printf("\n");
    for (i = 0; i < n; i++)
        printf("%s, ", a[i]);
    printf("\n");

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (strcmp(a[j], a[j + 1]) > 0)
            {
                strcpy(str, a[j]);
                strcpy(a[j], a[j + 1]);
                strcpy(a[j + 1], str);
            }
        }
    }

    printf("\n排序名称a[n]\n");
    for (i = 0; i < n; i++)
        printf("%s, ", a[i]);
    printf("\n");

    // b[n]与a[n]对应，记录每个名字出现次数
    int b[60];
    for (i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (strcmp(a[i], a[j]) == 0)
                count++;
        }
        b[i] = count;
    }

    /***********************************/
    printf("\nb[n]与a[n]对应，记录每个名字出现次数\n");
    for (i = 0; i < n; i++)
        printf("%d, ", b[i]);
    printf("\n");
    /***********************************/

    // 去掉重复的次数和名字数组
    int arrCount[60];
    char arrName[60][30];
    arrCount[0] = b[0];
    strcpy(arrName[0], a[0]);
    int position = 1;
    for (i = 1; i < n; i++)
    {
        if (strcmp(a[i], a[i - 1]) != 0)
        {
            strcpy(arrName[position], a[i]);
            arrCount[position] = b[i];
            position++;
        }
    }
    /***********************************/
    printf("\n去掉重复的次数和名字数组\n");
    for (i = 0; i < position; i++)
    {
        printf("%s, ", arrName[i]);
        printf("%d, ", arrCount[i]);
        printf("\n");
    }
    /***********************************/

    // 双数组按照次数大小排序
    for (i = 0; i < position - 1; i++)
    {
        for (j = 0; j < position - i - 1; j++)
        {
            if (arrCount[j] < arrCount[j + 1])
            {
                int temp = arrCount[j];
                arrCount[j] = arrCount[j + 1];
                arrCount[j + 1] = temp;

                strcpy(str, arrName[j]);
                strcpy(arrName[j], arrName[j + 1]);
                strcpy(arrName[j + 1], str);
            }
        }
    }

    /***********************************/
    printf("\n双数组按照次数大小排序\n");
    for (i = 0; i < position; i++)
    {
        printf("%s, ", arrName[i]);
        printf("%d, ", arrCount[i]);
        printf("\n");
    }
    /***********************************/

    return 0;
}