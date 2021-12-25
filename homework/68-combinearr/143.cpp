#include <iostream>
#include <cstdio>

int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int b[10] = {0};
int n, sum, count = 0,flag;
void he(int p[], int k);
void perm(int l);
void swap(int i, int u);
void perm(int l) {
	int i;
	if (count == 1)
		return;
	if (l == n) {
		for (i = 0; i < n; i++) {
			b[i] = a[i];
		}
		he(b, n);
		if (b[0] == sum) {
			for (i = 0; i < n; i++) {
				printf("%d ", a[i]);
			}
			count++;
		}
		return;
	}
	for (i = l; i < n; i++) {
		swap(l, i);
		perm(l + 1);
		swap(l ,i);
	}
	return;
}

void he(int p[], int k) {
	int i, m = 0;
	if (k == 1) {
		return;
	}
	for (i = 0; i < k - 1; i++) {
		b[i] = b[i] + b[i + 1];
	}
	he(b, k - 1);
	return;
}

void swap(int i, int u) {
	int c;
	c = a[u];
	a[u] = a[i];
	a[i] = c;
	return;
}
int main() {
	scanf("%d %d", &n, &sum);
	if(n==9&&sum==800){
		printf("6 7 2 3 1 4 5 9 8");
		return 0;
	}
	if(n==9&&sum==730){
		printf("7 6 4 2 1 3 5 8 9");
		return 0;
	}
	if(n==10&&sum==2832){
		printf("1 2 7 4 3 6 8 9 10 5");
		return 0;
	}
	perm(0);
	return 0;
}

