
// https://www.educative.io/edpresso/what-is-the-qsort-function-in-c

#include <stdlib.h> // needed to use qsort()
#include <stdio.h>
#include <string.h>

int comparator(const void *a, const void *b)
{
  const char *pa = a;
  const char *pb = b;

  return strcmp(pa, pb);
}

// driver code
int main()
{
  char strings[][20] = {"Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter"};
  size_t item_size = sizeof(strings[0]);
  size_t strings_len = sizeof(strings) / item_size;
  printf("The unsorted array is: %li\n", strings_len);
  for (int i = 0; i < strings_len; i++)
    printf("%s, ", strings[i]);
  puts("");


  qsort(strings, strings_len, item_size, comparator);

  printf("\nThe sorted array is: \n");
  for (int i = 0; i < strings_len; i++)
    printf("%s, ", strings[i]);

  puts("");
}