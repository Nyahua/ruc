#include <stdio.h>
#include <stdlib.h> // needed to use qsort()

int arr[][2] = {
    {1, 21},
    {2, 12},
    {3, 33},
    {4, 54},
    {5, 45},
};

int comparator(const void *p1, const void *p2)
{
    return (*(int *)p1 - *(int *)p2);
}

int comparator2(const void *p1, const void *p2)
{
    int *ptr1 = (int *)p1; 
    int *ptr2 = (int *)p2;
    return *(ptr1 + 1) - *(ptr2 + 1);
}

// driver code
int main()
{

    qsort(arr, 5, sizeof(arr[0]), comparator);
    printf("\nThe sorted array is: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("{%d, %d},\n", arr[i][0], arr[i][1]);
    }

    qsort(arr, 5, sizeof(arr[0]), comparator2);
    printf("\nThe sorted array is: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("{%d, %d},\n", arr[i][0], arr[i][1]);
    }
}
