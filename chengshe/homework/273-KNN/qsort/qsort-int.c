
// https://www.educative.io/edpresso/what-is-the-qsort-function-in-c

#include <stdlib.h> // needed to use qsort()
#include <stdio.h>

int arr[] = {20, 15, 36, -8, 2, 7};

int comparator (const void * p1, const void * p2)
{
  return (*(int*)p1 - *(int*)p2);
}

// driver code
int main ()
{
  printf("The unsorted array is: \n");
  for(int i = 0; i < 6; i++)
    printf("%d ", arr[i]);
    
  qsort(arr, 6, sizeof(int), comparator);
  printf("\nThe sorted array is: \n");
  
  for(int i = 0; i < 6; i++)
    printf("%d ", arr[i]);
  
  puts("");
}