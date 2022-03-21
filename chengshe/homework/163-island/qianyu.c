#include <stdio.h>
int n, m;
int area = 0;
int num = 0;
char ocean[102][102];


int island[102][102] = {{'\0'}};

int find_island(int i, int j) {
	area++;
	printf("%d ", area);
	island[i][j] = 1;
	int flag = 0;
	for (int t = -1; t <= 1; t++) {
		for (int k = -1; k <= 1; k++) {
			printf("%c ", ocean[i + t, j + k]);
			if (i + t >= 0 && i + t <= n - 1 && j + k >= 0 && j + k <= m - 1 && island[i + t][j + k] != 1
			        && ocean[i + t][j + k] == '|') {
				find_island(i + t, j + k);
				flag = 1;
			}
		}
	}
	if (flag == 0) {
		return area;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	int size;
	int max = 0;
	for (int i = 0; i < n; i++) {
		gets(ocean[i]);
		getchar();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ocean[i][j] == '|' && island[i][j] != 1) {
				num++;
				size = find_island(i, j);
				if (size > max) {
					max = size;
				}
			}

		}
	}
	find_island(0, 0);
	printf("%d %d", num, max);
	return 0;
}