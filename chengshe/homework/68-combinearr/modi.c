#include <stdio.h>
#include <stdlib.h>
int sum;
int n;
int flag = 0;

int state[100] = {0};
int result[100];

int max;
int min[100];
int amount(int num)
{
	int temp = 0;
	int arr[100];
	for (int i = 1; i <= num; i++)
		arr[i] = result[i];

	for (int j = 1; j <= num - 1; j++)
		for (int i = 1; i <= num - j; i++)
			arr[i] = arr[i] + arr[i + 1];

	return arr[1];
}

int array(int num)
{
	if (flag == 1)
		return 1;

	if (num == n)
		for (int i = 1; i <= 10; i++)
		{
			if (state[i])
				continue;
			result[num] = i;
			if (amount(num) == sum)
			{
				int total = 0;
				for (int j = 1; j <= n; j++)
				{
					// printf("%d ", result[j]);
					total += result[j];
					if (total > max)
					{
						for (int k = 1; k <= n; k++)
							printf("%d ", min[k]);
						exit(1);
					}
				}
				if (total < max)
				{
					max = total;
					for (int j = 1; j <= n; j++)
						min[j] = result[j];
				}
				// printf("total: %d max: %d\n", total, max);
				break;
				// exit(1);
				flag = 1;
				return 1;
			}
		}
	else
		for (int i = 1; i <= 10; i++)
		{
			if (flag)
				return 1;
			if (state[i])
				continue;
			state[i] = 1;
			result[num] = i;
			if (amount(num) >= sum)
			{ //判断数列中的数有没有超范围
				state[i] = 0;
				continue;
			}
			array(num + 1);
			state[i] = 0;
			result[num] = 0;
		}
}

int main()
{
	scanf("%d %d", &n, &sum);
	max = sum;
	array(1);
	for (int j = 1; j <= n; j++)
		printf("%d ", min[j]);
	puts("");
	return 0;
}