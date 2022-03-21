#include <stdio.h>

int main()
{
    int N, P, M;
    int i, j, k, mul; //muti是乘起来的两个数最后要把P个mul加在一起成为某一位的sum
    // int sum = 0; 不需要了
    scanf("%d %d %d", &N, &P, &M);
    getchar();

    // Variable-length arrays with automatic storage duration are allowed since C99.
    // In C89, it is not possible to allocate an array with automatic storage duration,
    // size of which is not known at the compile time.
    // https://stackoverflow.com/a/14936379
    int A[N][P], B[P][M], C[N][M];

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < P; j++)
        {
            scanf("%d", &A[i][j]);
            getchar();
        }
    }
    for (j = 0; j < P; j++)
    {
        for (k = 0; k < M; k++)
        {
            scanf("%d", &B[j][k]);
            getchar();
        }
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            C[i][j] = 0; // 矩阵元素初始化为0；
            // 元素开始累加
            for (k = 0; k < P; k++)
            {
                mul = A[i][k] * B[k][j];
                C[i][j] += mul;
            }
            // 累加完毕，开始打印
            printf("%d", C[i][j]);
            // 最后一位回车，否则空格
            if (j == (M - 1))
            {
                printf("\n");
            }
            else
            {
                printf(" ");
            }
        }
    }
    return 0;
}