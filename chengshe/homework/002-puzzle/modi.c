#include <stdio.h>
int puzzle[10][10];
int flag[10][10];
int score = 0;
int m, n;
int max = 0;

void travel(int i, int j)
{
	// printf("(%d, %d)", i, j);
	flag[i][j] = 0;
	score += puzzle[i][j];

	if (i == n && (j == m))
	{
		// printf("score:%d\n", score);
		if (score > max)
			max = score;
		return;
	}

	if (i < n && flag[i + 1][j])
	{
		travel(i + 1, j);
		score -= puzzle[i + 1][j];
		 flag[i + 1][j] = 1;
	}

	if (j < m && flag[i][j + 1])
	{
		travel(i, j + 1);
		score -= puzzle[i][j + 1];
		flag[i][j + 1] = 1;
	}

	if (flag[i][j-1])
	{
		travel(i, j-1);
		score -= puzzle[i][j-1];
		flag[i][j-1] = 1;
	}
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf("%d", &puzzle[i][j]);

	// 初始化flags数组，0排0列为0， 其余为1
	for (j = 0; j <= m; j++)
		for (i = 0; i <= n; i++)
			if (i == 0 || j == 0)
				flag[i][j] = 0;
			else
				flag[i][j] = 1;

	// for (i = 0; i <= n; i++)
	// {
	// 	for (j = 0; j <= m; j++)
	// 		printf("%d ", flag[i][j]);
	// 	puts("");
	// }

	travel(1, 1);
	printf("%d\n", max);

	return 0;
}