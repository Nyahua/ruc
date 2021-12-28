
// https://www.educative.io/edpresso/what-is-the-qsort-function-in-c

#include <stdlib.h> // needed to use qsort()
#include <stdio.h>

/* 比较函数都标准写法，p1, p2分别指向带比较元素 
   p1, p2为无类型指针，可以指向整数，字符及数组等
   在比较前需要对这两个指针指定数据类型:casting
*/
// 本比较函数比较每组数的第3个数的大小 a[][2]
int comparator(const void *p1, const void *p2)
{
  const int *a = p1; // 用整数型指针a代替指向第一行数组的无类型p1
  const int *b = p2; // 不使用 const也可以，但会有警告，因为p1是const;

  return a[2] - b[2]; // 比较两层的第三个元素
}

// 本比较函数比较每组数的第3个数的大小 a[][2]
// 如果第3个数相同就比较第一个数
int comparator2(const void *p1, const void *p2)
{
  int *a = p1;
  int *b = p2;

  if (a[2] == b[2])
    return a[0] - b[0];
  else
    return a[2] - b[2];
}

// driver code
int main()
{
  int arr[][3] = {{5, 2}, {2, 5}, {3, 6}, {4, 3}, {4, 5}};
  size_t item_size = sizeof(arr[0]);
  size_t arr_len = sizeof(arr) / item_size;
  printf("The unsorted array and sum of %li itmes:\n", arr_len);
  for (int i = 0; i < arr_len; i++)
  {
    arr[i][2] = arr[i][0] + arr[i][1];
    printf("%d, %d -> %d\n", arr[i][0], arr[i][1], arr[i][2]);
  }

  qsort(arr, arr_len, item_size, comparator);
  printf("The sorted array by sum: \n");
  for (int i = 0; i < arr_len; i++)
    printf("%d, %d -> %d\n", arr[i][0], arr[i][1], arr[i][2]);

  qsort(arr, arr_len, item_size, comparator2);
  printf("The sorted array by sum and 1st column: \n");
  for (int i = 0; i < arr_len; i++)
    printf("%d, %d -> %d\n", arr[i][0], arr[i][1], arr[i][2]);
}