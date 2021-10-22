#include <stdio.h>

int main() {
    char str[20];
    fgets(str, 20, stdin);
    printf("You just entered:\n%s\n", str);
    return 0;
}