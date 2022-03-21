#include <stdio.h>
int arr[1002][1002];
int flag[1002][1002];
int r, c; // row, column
int n;

void printArr()
{
    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
            printf("%d, ", arr[i][j]);
        puts("");
    }
    puts("++++++++++++++++++++++++++++");
}

void printFlag()
{
    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
            printf("%d, ", flag[i][j]);
        puts("");
    }
    puts("++++++++++++++++++++++++++++");
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n + 2; i++)
        for (int j = 0; j < n + 2; j++)
        {
            if (i == 0 || j == 0 || i == n + 1 || j == n + 1)
                flag[i][j] = 0;
            else
            {
                flag[i][j] = 1;
                scanf("%d", &arr[i][j]);
            }
        }

    printFlag();
    printArr();
}