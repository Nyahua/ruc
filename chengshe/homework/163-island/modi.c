#include <stdio.h>
int n, m;
int area = 0;
int num = 0;
char ocean[102][102];
int island[102][102];

int move(int i, int j)
{
    // printf("(%d, %d) ", i, j);
    island[i][j] = num;

    for (int t = -1; t <= 1; t++)
        for (int k = -1; k <= 1; k++)
            if ((ocean[i + t][j + k] == 'I') && (island[i + t][j + k] == 0))
                move(i + t, j + k);

    // printf("\n%d, %d: nowhere to go\n", i, j);
    return 0;
}

int main()
{
    int size;

    scanf("%d %d", &n, &m);
    // 初始化 ocean 为 '.'  islands为 0； 
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
        {
            ocean[i][j] = '.';
            island[i][j] = 0;
        }

    getchar();
    for (int i = 1; i <= n; i++)
    {
        gets(ocean[i] + 1);
        ocean[i][m + 1] = '.'; // replace \n
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (ocean[i][j] == 'I' && island[i][j] == 0)
            {
                num++;
                // printf("start from %d, %d:\n", i, j); // debug
                move(i, j);
            }

    // debug 看看island矩阵是否正确
    for (int i = 0; i <= n + 2; i++)
    {
        for (int j = 0; j <= m + 2; j++)
            printf("%d ", island[i][j]);

        puts("");
    } // debug END

    int counts[num + 1]; // 用来统计各个岛屿的面积
    for (int i = 1; i <= num; i++)
        counts[i] = 0;

    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            counts[island[i][j]]++; // island[i][j]为各个岛屿的id, 0为海洋

    // 看看个岛屿的面积
    for (int i = 1; i <= num; i++)
        printf("island %d: %d\n", i, counts[i]);

    int maxId = 0, maxArea = 0;
    for (int i = 1; i <= num; i++)
        if (counts[i] > maxArea)
        {
            maxArea = counts[i];
            maxId = i;
        }
    printf("%d %d\n", maxId, maxArea);
    return 0;
}