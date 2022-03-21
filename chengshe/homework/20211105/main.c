#include <stdio.h>

int main()
{
    int N, i, j, m, k, q, t;

    // inputs
    scanf("%d", &N);
    int a[N][2]; // id and score
    int mingci[N];
    mingci[0] = 1;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < 2; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // sort
    for (i = 1; i < N; i++)
    {
        for (j = 0; j < (N - i); j++)
        {
            if (a[j][1] < a[j + 1][1])
            {
                m = a[j][1];
                a[j][1] = a[j + 1][1];
                a[j + 1][1] = m;
                t = a[j][0];
                a[j][0] = a[j + 1][0];
                a[j + 1][0] = t;
            }
            if (a[j][1] == a[j + 1][1])
            {
                if (a[j][0] > a[j + 1][0])
                {
                    m = a[j][0];
                    a[j][0] = a[j + 1][0];
                    a[j + 1][0] = m;
                }
            }
        }
    }

    // ranking
    for (i = 0; i < N - 1; i++)
    {
        if (a[i + 1][1] == a[i][1])
        {
            mingci[i + 1] = mingci[i];
        }
        else
        {
            mingci[i + 1] = i+2;
        }
    }
    // print a
    for (i = 0; i< N; i++) {
        printf("%d: %d, %d\n", mingci[i], a[i][0], a[i][1]);
    }
    return 0;
    // end of print a

    
    for (i = 0; i < N; i++)
    {
        printf("%d ", mingci[i]);
        printf("%d ", a[i][0]);
        printf("%d\n", a[i][1]);
    }
    return 0;
}