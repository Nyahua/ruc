#include <stdio.h>
#include <string.h>
char a[200]; //被操作的
char b[100];  //命令行
//用于转移操作字符串
char c[200];
char d[200];

int g[200]; //记录重复字符的下标
int i, j, k;
int confirm(char a[], char c[], int m)
{
    for (i = m; i < strlen(c); i++)
    {
        if (a[i] != c[i - m])
        {
            return 0;
        }
    }
    return 1;
}

int count(char a[], char b[])
{
    k = 0;
    for (i = 2; i < strlen(b); i++)
    {
        c[i - 2] = b[i];
    }
    char *pB = strstr(a, c);
    char *pA;
    while (pB)
    {
        k++;
        pA = pB + strlen(c);
        pB = strstr(pA, c);
    }

    // printf("%s\n", c);
    return k;
}

// void deleting(char a[], char b[])
// {
//     k = 0;
//     for (i = 2; i < strlen(b); i++)
//     {
//         c[i - 2] = b[i];
//     }
//     char *pB = strstr(a, c);
//     char *pA;
//     while (pB)
//     {
//         k++;
//         pA = pB + strlen(c);
//         strcpy(pB, pA);
//         pB = strstr(pB, c);
//     }
// }

void deleting(char a[], char b[])
{
    char *c;
    strcpy(c, b+2);
    char *p = strstr(a, c);
    if (p)
    {
        char *temp;
        temp = p + strlen(c);
        strcpy(p, temp);
    }
}

void insert(char a[], char b[])
{
    for (i = 2; i < strlen(b); i++)
    {
        if (b[i] == ' ')
            break;
        c[i - 2] = b[i];
    }
    for (i = 3 + strlen(c); i < strlen(b); i++)
    {
        d[i - 3 - strlen(c)] = b[i];
    }
    char *p1 = a + strlen(a);
    while (!strstr(p1, c))
    {
        p1--;
    }
    char *p2 = d + strlen(d);
    char *p3;
    p3 = p1;
    strcpy(p2, p1);
    strcpy(p3, d);
    //   printf("%s %s ",c,p2);
    printf("%s ", a);
}
void replace(char a[], char b[])
{
    for (i = 2; i < strlen(b); i++)
    {
        if (b[i] == ' ')
            break;
        c[i - 2] = b[i];
    }
    for (i = 3 + strlen(c); i < strlen(b); i++)
    {
        d[i - 3 - strlen(c)] = b[i];
    }
    char *p1;
    char *p2;
    p1 = a;
    int t = strlen(d);
    int m = strlen(c);
    while (strstr(p1, c))
    {
        p2 = strstr(p1, c);

        strcpy(d + t, p2 + m);
        strcpy(p2, d);
        p1 = p2 + t;
    }
    printf("%s", a);
}
int main()
{
    gets(a);
    gets(b);
    if (b[0] == 'C')
    {
        //  count(a, b);
        printf("%d\n", count(a, b));
    }
    else if (b[0] == 'D')
    {
        deleting(a, b);
        printf("%s", a);
    }
    else if (b[0] == 'I')
    {
        insert(a, b);
    }
    else
    {
        replace(a, b);
    }
    return 0;
}