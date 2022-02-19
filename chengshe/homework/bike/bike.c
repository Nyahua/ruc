#include <stdio.h>
#include <math.h>
int main()
{
    int n; // 第1行，1个整数n，表示单车停放区数量
    scanf("%d", &n);

    /*
    arr[0][n]: 国图阅览室到各停车区的距离
    arr[1][n]: 各停车区当前的剩余车位数
    arr[2][n]: 停车区空余车位变化速度（个/每10分钟）
    arr[3][n]: 从人大东门骑到停车区的预估时间 (分钟)
    */
    int arr[4][n];
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // 把round(剩余车辆)>0的停车点记录到spots[]
    float bikeNum[n]; // number of bikes reamains
    int spots[n];     // usalbe parking spots
    int count = 0;    // number of usable parking spots
    for (i = 0; i < n; i++)
    {
        bikeNum[i] = arr[1][i] + (arr[2][i] * ((float)arr[3][i] / 10));
        if (round(bikeNum[i]) > 0) //(1.5 usable, 1.4 not)
        {
            spots[count] = i;
            count++;
        }
    }

    // 在spots[count]中找到最短距离
    int bestSpot = spots[0];
    int minDistance = arr[0][bestSpot];
    for (i = 0; i < count; i++)
    {
        if (arr[0][spots[i]] <= minDistance)
        {
            minDistance = arr[0][spots[i]];
            bestSpot = spots[i] + 1;
        }
    }
    printf("%d\n", bestSpot);
    //	printf("%d",round(24351.8));
    return 0;
}
