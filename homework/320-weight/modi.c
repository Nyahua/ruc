#include <stdio.h>
#include <stdlib.h>
int weight1[20];
int num[20];
int weight2[10005] = {0}; // 记录每个重量出现的次数,行数代表重量。
int n, m;
int maxZL = 0;

long long zuhe[300][2]; //第一列为重量，第二列为组合数
int alr = 0;			//已经有的重量
void weigh(int fm)
{
	if (fm == n)
	{
		weight2[alr]++;
		return;
	}
	for (int j = 0; j <= num[fm]; j++)
	{
		int temp = j * weight1[fm];
		if (alr + temp > maxZL)
			break;
		alr += temp;
		weigh(fm + 1);
		alr -= temp;
	}
}

int cmparray(const void *p1, const void *p2)
{
	const long long *a = p1;
	const long long *b = p2;
	return b[1] - a[1];
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &weight1[i]); //砝码重量从零开始

	for (int j = 0; j < n; j++)
		scanf("%d", &num[j]); //砝码的数量，从零开始

	for (int i = 0; i < m; i++)
	{
		scanf("%lli", &zuhe[i][0]); //待称物体的重量，从零开始
		if (zuhe[i][0] > maxZL)
			maxZL = zuhe[i][0];
	}

	int alr = 0; //已经有的重量
	weigh(0);
	for (int i = 0; i < m; i++)
		zuhe[i][1] = weight2[zuhe[i][0]];

	qsort(zuhe, m, sizeof(zuhe[0]), cmparray);
	for (int i = 0; i < m; i++)
		printf("%lli:%lli\n", zuhe[i][0], zuhe[i][1]);

	return 0;
}