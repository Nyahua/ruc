#include <stdio.h>
#include <stdlib.h>

/********** SUPPORTING FUNCTIONS ***********/
#include <time.h>
#define RANDMAX 100 // ceiling of rand int

int *randArray(size_t nums)
{
	srand(time(NULL));
	int *arr = (int *)malloc(nums * sizeof(int));
	for (int i = 0; i < nums; i++)
	{
		arr[i] = rand() % RANDMAX;
	}
	return arr;
}

void printArray(int arr[], int nums)
{
	printf("{");
	for (int i = 0; i < nums - 1; i++)
		printf("%d, ", arr[i]);
	printf("%d}\n", arr[nums - 1]);
}

/********** END OF SUPPORTING FUNCTIONS ***********/

void mySort(int *ary, int left, int right)
{
	int flag;

	if (left >= right) // right来自于low-1,有可能是0-1，小于left，而不是==
	{
		return;
	}

	int i, j, k;
	int low = left;
	int high = right;
	int guard = ary[left];
	do
	{
		while (low < high && ary[high] > guard)
			high--;
		if (low < high)
		{
			ary[low] = ary[high];
			low++;
		}
		while (low < high && ary[low] < guard)
			low++;
		if (low < high)
		{
			ary[high] = ary[low];
			high--;
		}
		ary[low] = guard; // 放回最后一个萝卜

	} while (low != high);
	mySort(ary, left, low - 1);
	mySort(ary, low + 1, right);
}

int main()
{
	int n = 10; // nums of array
	int *arr = randArray(n);
	printArray(arr, n);
	mySort(arr, 0, n - 1);
	printArray(arr, n);

	return 0;
}