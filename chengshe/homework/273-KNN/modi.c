#include <stdio.h>
#include <math.h>

int paixu[10000][3];//距离在前，类别在后，用于排序,从零开始
int partition(int left, int right) {
    if (left < right) {
        int l = left;
        int r = right;
        int target = paixu[l][0];
        int temp = paixu[l][1];
        while (l < r) {
            while (l < r && target <= paixu[r][0])
                r--;
            if (l < r) {
                paixu[l][0] = paixu[r][0];
                paixu[l][1] = paixu[r][1];
                l++;
            }
            while (l < r && target > paixu[l][0])
                l++;
            if (l < r) {
                paixu[r][0] = paixu[l][0];
                paixu[r][1] = paixu[l][1];
                r--;
            }
        }
        paixu[l][0] = target;
        paixu[l][1] = temp;
        return l;
    }
}

void quicksort(int left, int right) {
    int m = partition(left, right);
    if (left >= right)
        return;
    quicksort(left, m - 1);
    quicksort(m + 1, right);
    return;
}

int main() {
    int m, k;
    int times[200] = {'\0'}; //记录每一个类别的最近点出现了几次
    scanf("%d %d", &m, &k);
    int a[200][200];
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i][0]);
        for (int j = 1; j <= 2 * a[i][0]; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int x;
    int y;
    scanf("%d %d", &x, &y);
    int t = 0;
    for (int i = 0; i < m; i++) { //重新把a数组改为距离的数组
        for (int j = 1; j <= a[i][0]; j++) {
            paixu[t][0] = pow(a[i][2 * j - 1] - x, 2) + pow(a[i][2 * j] - y, 2);
            paixu[t][1] = i + 1;
            //      printf("%d %d\n", paixu[t][0], paixu[t][1]);
            t++;
        }
    }
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += a[i][0];
    }
    quicksort(0, sum - 1);
    int w = k;

    while (paixu[w][0] == paixu[k - 1][0]) {
        w++;
        //  printf("%d\n", w);
    }
    k = w;
    for (int i = 0; i < w; i++) {
        times[paixu[i][1]]++;
    }
    int max1 = 1;
    int max2 = times[1];

    for (int i = 1; i <= m; i++) {
        if (max2 < times[i]) {
            max2 = times[i];
            max1 = i;

        }
    }
    printf("%d\n", max1);
    return 0;