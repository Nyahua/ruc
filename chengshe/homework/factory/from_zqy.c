#include <stdio.h>
int main()
{
    int arr[8] = {125, 45, 90, 60, 110, 140, 70, 100};
    int Ma, Mb, Mc, w;
    /* 
    wrong! Mc without &
    scanf("%d %d %d", &Ma, &Mb, Mc);
    */
    scanf("%d %d %d", &Ma, &Mb, &Mc);
    int i, j, k;
    int fa[336][4];
    int x, y, z;
    int flag = 0;
    for (i = 0; i < 8; i++)
    {
        if (arr[i] >= Ma)
        {
            x = arr[i] - Ma;
            for (j = 0; j < 8; j++)
            {
                if (arr[j] >= Mb && j != i)
                {
                    y = arr[j] - Mb;
                    for (k = 0; k < 8; k++)
                    {
                        if (arr[k] >= Mc && k != i && k != j)
                        {
                            z = arr[k] - Mc;
                            flag++;
                            fa[flag - 1][0] = x + y + z;
                            fa[flag - 1][1] = i + 1;
                            fa[flag - 1][2] = j + 1;
                            fa[flag - 1][3] = k + 1;
                        }
                    }
                }
            }
        }
    }

    /* ? print lazy hours?
    for (i = 0; i < flag; i++)
    {
        printf("%d ", flag);
    }
    */
    printf("\n********Begin of Debug************\n\n");
    for (i = 0; i < flag; i++)
    {
        printf("%d ", fa[i - 1][0]);
    }
    printf("\n********End of Debug************\n\n");
    /* end of debug, delete previous lines */

    if (flag == 0)
    {
        printf("-1");
        return 0;
    }

    for (i = 0; i < flag; i++)
    {
        for (j = 0; j < flag - i - 1; j++)
        {
            /*
            from smaller to bigger,
            so if next if smaller, swap
            if (fa[j + 1][0] > fa[j][0])
            */
            if (fa[j + 1][0] < fa[j][0])
            {
                w = fa[j][1];
                fa[j][1] = fa[j + 1][1];
                fa[j + 1][1] = w;
                w = fa[j][2];
                fa[j][2] = fa[j + 1][2];
                fa[j + 1][2] = w;
                w = fa[j][3];
                fa[j][3] = fa[j + 1][3];
                fa[j + 1][3] = w;
                w = fa[j][0];
                fa[j][0] = fa[j + 1][0];
                fa[j + 1][0] = w;
            }
        }
    }
    for (i = 0; i < flag; i++)
    {
        if (fa[i][0] == fa[0][0])
            printf("%d %d %d\n", fa[i][1], fa[i][2], fa[i][3]);
    }
    return 0;
}