#include <stdio.h>
#include <stdlib.h>

int cmparray(const void *p1, const void *p2)
{
    const int *pa = p1;
    const int *pb = p2;

    if (pa[3] == pb[3])
        return pa[0] - pb[0];
    else
        return pa[3] - pb[3];
}

int main()
{
    int paixu[10000][4] = {0}; //class, x, y, distance,

    int m, k;
    scanf("%d %d", &m, &k);
    int total_nums = 0; // 总样本数
    for (int i = 0; i < m; i++)
    {
        int nums; // 本类样本数
        scanf("%d", &nums);
        for (int j = 0; j < nums; j++)
        {
            paixu[total_nums][0] = i + 1;                                 // 记录类别
            scanf("%d %d", &paixu[total_nums][1], &paixu[total_nums][2]); // 记录坐标x, y
            total_nums++;                                                 // 记录完毕，样本数加一
        }
    }
    int x, y;
    scanf("%d %d", &x, &y);

    for (int i = 0; i < total_nums; i++) // 计算距离，好像pow()返回float类型
        paixu[i][3] = (paixu[i][1] - x) * (paixu[i][1] - x) + (paixu[i][2] - y) * (paixu[i][2] - y);

    qsort(paixu, total_nums, sizeof(paixu[0]), cmparray);
    /* ----------DEBUG---------- */
    for (int i = 0; i < total_nums; i++)
        printf("%d: (%d, %d) -> %d\n", paixu[i][0], paixu[i][1], paixu[i][2], paixu[i][3]);
    /* ------ DEBUG  END ------- */

    int times[200] = {0}; // class, times of class
    if (k > total_nums)
        k = total_nums;

    for (int i = 0; i < k; i++)
    {
        times[paixu[i][0]]++; // 哪一类在paixu的前k出现一次，那一类就在times类行增加一次

        /* 如果最相似第k+1、k+2、……、k+j样本到待分类样本的距离等于最相似的第k个样本到待分类样本的距离，
        那么确定待分类样本的类别是需要考虑这j个样本。*/
        if (i >= k - 1 && paixu[i][3] == paixu[i + 1][3])
            k++;
    }
    int maxclass, maxtimes = 0;
    for (int i = 0; i < m + 1; i++)
    {
        printf("class:%d: times: %d\n", i, times[i]);
        if (times[i] > maxtimes)
        {
            maxtimes = times[i];
            maxclass = i;
        }
    }

    printf("%d\n", maxclass);
    return 0;
}