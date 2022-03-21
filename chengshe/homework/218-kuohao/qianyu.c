#include <stdio.h>
#include <string.h>

void findbig(char a[]) {
	char *p1 = strstr(a, "{}");
	if (p1) {
		while (*p1) {
			*p1 = *(p1 + 2);
			p1++;
		}

	}
}

void findsmall(char b[]) {
	char *p2 = strstr(b, "()");
	if (p2) {
		while (*p2) {
			*p2 = *(p2 + 2);
			p2++;
		}
	}
}

void check(char a[]) {
    
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] == '(' || a[i] == ')' || a[i] == '{' || a[i] == '}')
			continue;
		else {
			// strcpy(a + i, a + i + 1);
			// i--;
            memmove(a+i, a+i+1, strlen(a));
            i--;
		}
	}
	puts(a);
	printf("&&&");
//	int flag;
	char *p1 = strstr(a, "{}");
	char *p2 = strstr(a, "()");
	int len, newlen;
	while (1) {
		len = strlen(a);
		findbig(a);
		findsmall(a);
		newlen = strlen(a);
		if (len == newlen) {
			break;
		}
	}

	if (newlen) {
		puts("false");
	} else
		puts("true");

}

int main() {
	int n;
	char a[100][501];
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) { //a行列均为从零开始
		gets(a[i]);
	}
	for (int i = 0; i < n; i++) {
		check(a[i]);
	}
	return 0;
}