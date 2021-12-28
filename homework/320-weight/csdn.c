
/*  
https://blog.csdn.net/weixin_30954607/article/details/97555215
(我们用数组w[i]表示每个砝码的重量，用a[i]表示每个砝码有多少个，1=<i<=6 )
Q[i,j]表示用前i个砝码是否能称量重量为j的物品。
Q[i,j]=1表示可以称量，Q[i,j]=0表示不能称量。
那么状态转移方程为：
     Q[i,j]=Q[i-1,j] or Q[i-1,j-w[i]] or Q[i-1,j-2*w[i]]....or Q[i-1,j-k*w[i]]
其中k=min{a[i],|j/w[i]|}(向下取整)，边界条件为：Q[0,0]=1,最终要求的值为Q[6,j]=1的那些j， 
1=<j<=N (N=SUM(w[i]*a[i]))，设定砝码总的重量为N,代码如下：
*/
//背包问题的扩展：砝码问题a保存每种砝码的个数，w保存每种砝码的重量,n是砝码的种类数。

void WeightPro(int *a, int *w, int n)
{
    //首先计算总的重量
    int N = 0;
    for (int i = 1; i <= n; i++)
    {
        N += a[i] * w[i];
    }

    //首先定义一个二维bool数组
    bool **Q = new bool *[n + 1];

    for (int i = 0; i <= n; i++)
    {

        Q[i] = new bool[N + 1]();
    }

    Q[0][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            int q = j / w[i];
            int k = q > a[i] ? a[i] : q;

            for (int p = 0; p <= k; p++)
                Q[i][j] |= Q[i - 1][j - p * w[i]];
        }
    }

    int count = 0;

    cout << "总重量为：" << N << endl;

    for (int i = N; i > 0; i--)
    {

        if (Q[n][i])
        {

            count++;

            cout << "能够称量重量为:" << i << "的物品" << endl;
        }
    }

    cout << "不同重量个数为:" << count << endl;
}