#include <stdio.h>

int main()
{
    /* inputs */
    int n;
    scanf("%d", &n);
    int i, j;

    int tree[101][101];

    for (i = 1; i <= n; i++)    // 最上面的层数为1，最下面的为n
        for (j = 0; j < i; j++) // 每一层的节点数等于层数。
            scanf("%d", &tree[i][j]);

    /*climbing the tree*/
    for (i = n - 1; i > 0; i--) // 从倒数第二层开始往上爬
    {
        for (j = 0; j < i; j++)
        {
            int maxSon; // 选择当前节点下面两个节点较大者
            if (tree[i + 1][j] > tree[i + 1][j + 1])
                maxSon = tree[i + 1][j];
            else
                maxSon = tree[i + 1][j + 1];

            // 当前节点数与下面较大者累加
            tree[i][j] += maxSon;
        }
    }

    puts("***********累加树**********************");
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < i; j++)
            printf("%d ", tree[i][j]);
        puts("");
    }
    
    printf("best sum: %d\n", tree[1][0]);
}
