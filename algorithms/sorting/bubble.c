#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int nums)
{
    printf("{");
    for (int i = 0; i < nums - 1; i++)
        printf("%d, ", arr[i]);
    printf("%d}\n", arr[nums - 1]);
}

int main()
{
    int n; // nums of array
    puts("Enter how many values to sort:");
    scanf("%d", &n);
    srand(time(NULL));
    int arr[n];
    for (int i = 0; i < 5; i++)
    {
        arr[i] = rand() % 20;
    }
    printArray(arr, n);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        printArray(arr, n);
    }

    return 0;
}