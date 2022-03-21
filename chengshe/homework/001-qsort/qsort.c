#include <string.h>
#include <stdio.h>

int ary[5] = {1, 5, 4, 3, 2};

int partition(int ary[], int left, int right) 
/* 从left到right对数组分出左右两个区间
   返回值m为分解点（轴），轴左边的都比轴上的值小
   轴右边的都比轴的值大 */ 
{ // ？为了避免进入死循环，这一步必须处理好等于的情f况
    int flag = ary[left]; // 用最左面的数字作为轴，计入flag，拔出第一个坑在left这个位置
    int l = left;
    int r = right;
    do
    {
        while (ary[r] > flag) // 坑在左边，从右边开始找第一个小于轴flag的值的位置r
            r--;
        if (ary[r] < flag && r > l) // 找到第一个小于flag的值，确认右侧的指针r还在l的右边
        {
            ary[l] = ary[r]; // 把这个小于轴的值放在轴左边挖出的坑里，目前右侧的坑在r
            l++; // 左侧指针从左坑里向右移动一位；
        }
        while (ary[l] < flag && r > l) // 从左侧当前指针位置开始向右侧移动，直到找到大于轴的值
            l++;
        if (ary[l] > flag && r > l) // 找到了这个值就拔出来放在右边的坑里
        {
            ary[r] = ary[l];
            r--;
        }
    } while (r > l); // 继续做轴的两侧寻找不符合要求的值移动，直到右侧指针不在l右侧了，应该是只有等于的情况
    int m = r;
    return m;
}

void quicksort(int ary[], int left, int right)
{

    int m = partition(ary, left, right);
    while (left <= right)
    {
        quicksort(ary, m, right);
        quicksort(ary, left, m);
    }
    return;
}

int main()
{
    quicksort(ary, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", ary[i]);
    }

    return 0;
}