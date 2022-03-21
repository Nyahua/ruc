#include <stdio.h>
#include <stdlib.h>

int state[100];
int n;
int gunzi[100];


int make_gunzi(int len, int gunzi_zongshu, int time, int alr)
{ //分别表示每根棍子的长度，第几根棍子和该棍子已经有的长度
	//printf("jinruhanshu\n");
	int flag = 0;
	if (alr == len)
	{
		// make_gunzi(len, gunzi_zongshu, time + 1, 0);
		return 1;
	}

	for (int j = 0; j < n; j++)
	{
		if ((!state[j]) && alr + gunzi[j] <= len)
		{
			flag = 1;
			state[j] = 1;
			alr += gunzi[j];
			if (make_gunzi(len, gunzi_zongshu, time + 1, alr))
				break;
			alr -= gunzi[j];
			state[j] = 0;
		}
	}
	if (flag == 0)
	{
		//	printf("wujie\n");
		return 0;
	}
}

int main()
{

	scanf("%d", &n);
	int sum_length = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &gunzi[i]);
		sum_length += gunzi[i];
	}

	for (int i = 1; i <= sum_length; i++)
	{ //i是指平均每根棍子的长度
		if (sum_length % i == 0 && (sum_length / i <= n) && i >= gunzi[n - 1])
		{
			//printf("jinrugaipanduan");
			if (make_gunzi(i, sum_length / i, 1, 0) == 1)
			{
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}