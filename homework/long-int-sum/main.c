#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    int first, k, i, j, b;
    scanf("%x %d", &first, &k);
    int z = 16 - first;
    int arr[z][k], output[k];
    int c = first;
    int sum;
    for (i = 0; i < z; i++)
    {
        first = c + i;
        for (j = 0; j < k; j++)
        {
            if ((first + j) > 15)
                b = first + j - 16;
            else
                b = first + j;
            arr[i][j] = b;
            printf("%d, ", arr[i][j]);
        }
        printf("\n");
    }

    int jinwei = 0;
    for (j = k-1; j <= 0; j++)
    {
        sum = jinwei;
        for (i = 0; i < z; i++)
        {
            sum += arr[i][j];
        }
        output[j] = sum % 10;
        jinwei = sum / 10;


        printf("%d, ", output[j]);
    }

    return 0;
}