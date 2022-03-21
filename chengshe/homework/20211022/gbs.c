#include <stdio.h>

int gbs(int a, int b) {
    int t = (a > b) ? a : b;
    while ( 1 ) {
        if ((t % a == 0) && (t % b == 0)) {
            return t;
        }
        else {
            ++t;
        }   
    }
}
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", gbs(a, b));
    return 0;
}


