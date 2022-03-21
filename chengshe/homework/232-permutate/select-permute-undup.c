// C program to print all permutations without duplicates allowed
#include <stdio.h>
#include <string.h>
int n;
char a[510], res[510] = {0};
int flag[500] = {0};
int count = 0;

/* Function to print permutations of string */
void permute(int l)
{
    char last = 0;
    if (l == n)
    {
        count += 1;
        printf("%s\n", res);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (flag[i] == 0 && a[i]!= last) 
            {

                res[l] = a[i];
                last = a[i];
                flag[i] = 1;
                permute(l + 1);
                flag[i] = 0;
            }
        }
    }
}

/* Driver program to test above functions */
int main()
{

    // scanf("%d", &n);
    // scanf("%s", a);
    n = 4;
    strcpy(a, "egge");

    /* sorting a[n] */
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
    /* a[n] sorted */

    permute(0);
    printf("%d\n", count);
    return 0;
}
