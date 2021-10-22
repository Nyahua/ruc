#include <stdio.h>

int A, B;

int f(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }

    return (A * f(n-1) + B * f(n-2)) % 7;
}

int main() {
    int n;
    scanf("%d %d %d", &A, &B, &n);
    printf("%d\n", f(n));

    return 0;
}
