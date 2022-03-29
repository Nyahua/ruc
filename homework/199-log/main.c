#include <stdio.h>
#include <stdlib.h>

int cmpintarr(const void *p1, const void *p2)
{
    const long long *a = p1; // p1, p2 为指向2维数组某一行的指针
    const long long *b = p2; // a, b 为同样的指针，但被赋予了与二维数组相同的数据类型
    return a[0] - b[0];      // 对两行数据都第一列进行比较
}

int main()
{
    int n; // 用户数量
    scanf("%d", &n);
    long long user[n][2]; // 用户入网记录
    for (int i = 0; i < n; i++)
        scanf("%lli %lli", &user[i][0], &user[i][1]);
    qsort(user, n, sizeof(user[0]), cmpintarr);

    // puts("+++++ DEBUG +++++");
    // for (int i = 0; i < n; i++)
    //     printf("%lli %lli\n", user[i][0], user[i][1]);
    /* ++++++++++++++++++++++*/

    long long login = user[0][0], logout = user[0][1]; // 用来记录当前时段有用户的登入登出时间，先用第一个客户的进出时间
    long long online, offline;                         // 用来记录当前有用户时段的时间，及到上一有用户时段的间隔；
    long long maxOnline = 0, maxOffline = 0;           // 用来记录最大有、无用户时间

    // 按照用户的登录次序开始遍历用户在线情况
    for (int i = 1; i < n; i++)
    {
        // 如果当前用户在当前登出的时间内登入， 并且更晚登出
        // 则延长了当前在线时间
        if (user[i][0] <= logout && user[i][1] > logout)
        {
            logout = user[i][1];     //登出时间已较晚登出者为准
            online = logout - login; // 计算当前在线时间
            if (online > maxOnline)  // 比较最大在线时间
                maxOnline = online;
        }

        // 如果当前用户登入时间晚于当前在线时间
        // 则出现了无用户在线期间，并开始了新的在线时段
        if (user[i][0] > logout)
        {
            login = user[i][0];
            offline = login - logout; // 当前离线时间
            if (offline > maxOffline)
                maxOffline = offline;
            logout = user[i][1];
        }

        // printf("i: %d, login: %lli, logout: %lli, online: %lli, offline: %lli\n", i, login, logout, online, offline);
    }
    printf("%lli %lli\n", maxOnline, maxOffline);
}