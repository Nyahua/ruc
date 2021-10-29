#include <stdio.h>

int main() {
	int N, P, M;
	int i, j, k, mul; //muti是乘起来的两个数最后要把P个mul加在一起成为某一位的sum
	int sum = 0;
	scanf("%d %d %d", &N, &P, &M);

    
	int A[N][P], B[P][M], C[N][M];
    // 这个数组的定义有问题：
    // 在C语言中，不能这样定义没有确定范围的数组
    // 在NPM不确定的情况下，会出现内存溢出
    // 可以按照最大范围定义数组，
    // 动态数组的定义可能在指针课程中讲
    // int A[2][5], B[5][5], C[2][5];

	getchar();
	for (i = 0; i < N; i ++) {
		for (j = 0; j < P; j ++) {
			scanf("%d", &A[i][j]);
			getchar();
		}
	}
	for (j = 0; j < P; j ++) {
		for (k = 0; k < M; k ++) {
			scanf("%d", &B[j][k]);
			getchar();
		}
	}
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			for (k = 0; k < P; k ++) {
				mul = A[i][k] * B[k][j];
				sum = sum + mul;
				C[i][j] = sum;
			}

		}
	}

	for (i = 0; i < N; i ++) {
		for (j = 0; j < M - 1; j ++) {
			printf("%d", C[i][j]);
		}
		if (j == M) {
			printf("%d\n", C[i][M]);
		}
	}
	return 0;
}