#include <stdio.h>
int puzzle[10][10];
int score = 0;
int flag = 0;
int m, n;
int k;
int max = 0;

void travel(int i, int j) {
	score += puzzle[i][j];
	if (i == n - 1 && j == m - 1) {
		printf("%d\n", score);
		if (score > max) {

			max = score;
		}
		score -= puzzle[i][j];
	}
	if (i < n - 1) {
		travel(i + 1, j);
		score -= puzzle[i + 1][j];

	}
	if (j < m - 1) {
		travel(i, j + 1);
		score -= puzzle[i][j + 1];
	}

}

int main() {
	int m, n;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &puzzle[i][j]);
		}
	}
	travel(0, 0);
	int max = 0;
	printf("%d\n", max);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			printf("%d ", puzzle[i][j]);
//		}
//		printf("\n");
//	}

	return 0;
}