#include <stdio.h>
int n;
int a[20];//原数列
int b[20];//储存每一次新的排列，打印完毕之后可以作废
int state[20];//记录每个元素的状态
int i, j, k;

void arrange(int t) {
	if (t == n - 1) {
//		for (i = 0; i < n; i++) {
//			if (state[i] == 1)
//				continue;
//			b[t] = a[i];
//			state[i] = 1;
//		}
		for (j = 0; j < n; j++) {
			printf("%d ", b[j]);
		}
		printf("\n");
		return;
	}

	for (i = 0; i < n; i++) {
		if (state[i] == 1) {
			continue;
		}
		b[t] = a[i];
		state[i] = 1;
		arrange(t + 1);
		state[i] = 0;
	}
}

int main() {
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				k = a[j];
				a[j] = a[j + 1];
				a[j + 1] = k;
			}
		}
	}

	arrange(0);
	return 0;
}