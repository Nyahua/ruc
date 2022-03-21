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
    //	for(i =0;i<n;i++)
    //	{
    //		puts(a[i]);
    //	}
    int b[60];
    char c[60][30];
    int num = 0;
    int aa = 0;
    int count = 1;
    for (i = 0; i < n; i += (num + 1))
    {
        aa = 1;
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(a[i], a[j]) == 0)
            {
                aa++;
                b[i - count + 1] = aa;
                strcpy(c[i - count + 1], a[i]);
            }
            else
            {
                puts(c[i + 1 - count]);
                printf("%d\n", b[i - count + 1]);
                count++;
                break;
            }
        }
    }
    printf("%d\n", count);
    for (i = 0; i < count; i++)
    {
        puts(c[i]);
    }
    return 0;
}