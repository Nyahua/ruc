#include <stdio.h>
int weight1[20];
int num[20];
int weight2[300];
int n, m;

long long zuhe[300][3];//第一列为重量，第二列为组合数
int alr = 0; //已经有的重量
void weigh(int fm, int zl, int i) { //分别表示用到第几个砝码和重量是多少
	if (fm == n) {
		if (alr == zl) {
			//	printf("%d %d\n", zl, i);
			zuhe[i][1]++;
		}
		return;
	}
	for (int j = 0; j <= num[fm]; j++) {
		int temp = j * weight1[fm];
		if (alr + temp > zl)
			break;
		alr += temp;
		weigh(fm + 1, zl, i);
		alr -= temp;
	}
}

int partition(int left, int right) {
	if (left < right) {
		int l = left, r = right;
		long long target = zuhe[l][1];
		int temp = zuhe[l][0];
		while (l < r) {
			while (l < r && target > zuhe[r][1])
				r--;
			if (l < r) {
				zuhe[l][1] = zuhe[r][1];
				zuhe[l][0] = zuhe[r][0];
				l++;
			}
			while (l < r && target < zuhe[l][1])
				l++;
			if (l < r) {
				zuhe[r][1] = zuhe[l][1];
				zuhe[r][0] = zuhe[l][0];
				r--;
			}
		}
		zuhe[l][0] = temp;
		zuhe[l][1] = target;
		return l;
	}
}

void quicksort(int left, int right) {
	int m = partition(left, right);
	if (left >= right)
		return;
	quicksort(m + 1, right);
	quicksort(left, m - 1);
	return;
}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &weight1[i]); //砝码重量从零开始
	}
	for (int j = 0; j < n; j++) {
		scanf("%d", &num[j]); //砝码的数量，从零开始
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &weight2[i]); //待称物体的重量，从零开始
		zuhe[i][0] = weight2[i];
		weigh(0, weight2[i], i);

	}
	quicksort(0, m - 1);
	for (int i = 0; i < m; i++) {
		printf("%d:%d\n", zuhe[i][0], zuhe[i][1]);
	}

	return 0;
}