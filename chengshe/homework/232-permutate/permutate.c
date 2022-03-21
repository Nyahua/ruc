// C program to print all permutations with duplicates allowed
#include <stdio.h>
#include <string.h>
int n;
char a[200];
/* Function to swap values at two pointers */
void swap(char x, char y)
{
    char temp;
    temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

/* Function to print permutations of string
This function takes three parameters:
1. String
2. Starting index of the string
3. Ending index of the string. */
void permute(int l, int r)
{
    int i;
    if (l == r)
        printf("%s\n", a);
    else
    {
        for (i = l; i <= r; i++)
        {
            if ((a[i] != a[l]) )
            {
                // printf("(%d, %d) =>", i, l);
                swap(l, i);
                permute(l + 1, r);
                swap(l, i); //backtrack}}
                // puts("");
            }
            else
                printf("%s\n", a);
        }
    }
}

/* Driver program to test above functions */
int main()
{

    scanf("%d", &n);
    scanf("%s", a);
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                swap(i, j);
    // printf("%s\n", a);
    permute(0, n - 1);
    return 0;
}
