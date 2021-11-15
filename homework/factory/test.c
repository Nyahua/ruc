#include <stdio.h>
int main()
{
    int arr[8] = {125, 45, 90, 60, 110, 140, 70, 100};
    int Ma, Mb, Mc, w;
    scanf("%d %d %d", &Ma, &Mb, &Mc);
    int i, j, k;
    int fa[336][4];
    int x, y, z;
    int flag = 0;
    minlazy = 0;
    for (i = 0, i < 8, i++)
        minLazy += arr[i];
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
                            printf("w:%d, (%d, %d, %d)", fa[flag - 1][0], fa[flag - 1][1], fa[flag - 1][2], fa[flag - 1][3]);
                        }
                    }
                }
            }
        }
    }

    return 0;
}