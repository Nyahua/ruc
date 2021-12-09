// https://zhuanlan.zhihu.com/p/130357860

#include <stdio.h>
#include <stdlib.h> // needed to use qsort()

int arr[] = {20, 15, 36, -8, 2, 7};

int comparator(const void *p1, const void *p2)
{
    int *ptr1 = (int *)p1; // convert void pointer to int
    int *ptr2 = (int *)p2;
    return *ptr1 - *ptr2; // compare the values pointing at
    // in  one line: return (*(int *)p1 - *(int *)p2);
}

// driver code
int main()
{
    qsort(arr, 6, sizeof(int), comparator);
    printf("\nThe sorted array is: \n");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
}