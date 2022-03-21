#include <stdio.h>
int n = 3;
int a[3] = {5, 8, 3};
int state[20] = {0}; //记录每个元素的状态
int q[20] = {0};

/*


*/
void arrange(int n, int m, int idx)
{
    if (idx >= m)
    {
        for (int i = 0; i < n; i++)
            printf("%d ", a[q[i]]);
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (state[i]) continue;
        q[idx] = i;
        state[i] = 1;
        arrange(n, m, idx + 1);
        state[i] = 0;
    }
}

int main()
{
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

    arrange(3, 3, 0);

    return 0;
}