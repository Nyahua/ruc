#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n;
long long goal;
long long arr[1002];
int times = 0;

int find(int left, int right)
{
    times++;
    // printf("time: %d, (%d, %d); ", times, left, right);

    if (left >= right)
    {
        //		printf("%d \n", times);
        return -1;
    }
    //	if (arr[left] == goal) {
    //		return left;
    //	}
    //	if (arr[right] == goal) {
    //		return right;
    //	}
    //	printf("%d", times);

    int guard = (left + right) / 2;

    if (arr[guard] == goal)
    {
        // printf("%d \n", times);
        return guard;
    }
    else if (arr[guard] > goal)
    {
        return find(left, guard - 1);
    }
    else
    {
        return find(guard + 1, right);
    }
}

int cmp(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
        return 1;
    else if (*(int *)a == *(int *)b)
        return 0;
    else
        return -1;
}

int main()
{
    scanf("%d", &n);
    scanf("%lld", &goal);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    qsort(arr, n, sizeof(arr[0]), cmp); //快速排序对了
                                        //	for (int i = 0; i < n; i++) {
                                        //		printf("%d ", arr[i]);
                                        //	}
    int pos = find(0, n - 1);
    printf("%d\n%d\n", pos, times);
    return 0;
}