#include <stdio.h>
int n = 3;
// int a[20];     //原数列
int a[3] = {5, 8, 3};
int b[20];           //储存每一次新的排列，打印完毕之后可以作废
int state[20] = {0}; //记录每个元素的状态
// int i, j, k;

void arrange(int t)
{
    if (t == n)
    {

        for (int j = 0; j < n; j++)
        {
            printf("%d ", b[j]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (state[i])
            continue;
        b[t] = a[i];
        state[i] = 1;
        arrange(t + 1);
        state[i] = 0;
    }
}

int main()
{
    // scanf("%d", &n);
    // for (i = 0; i < n; i++)
    // {
    //     scanf("%d", &a[i]);
    // }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int k = a[j];
                a[j] = a[j + 1];
                a[j + 1] = k;
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d, ", a[i]);
    puts("");

    arrange(0);
    return 0;
}