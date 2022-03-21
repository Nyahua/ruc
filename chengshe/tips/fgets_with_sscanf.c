#include <stdio.h>

int main() {
    // read stdin to string
    char str[100], substr1[10], substr2[100];
    fgets(str, 100, stdin);

    // scan str to first 10 char and the rest
    sscanf(str," %10[^\n]%100[^\n]", substr1, substr2);

    printf("Out:\n%s\n%s\n", substr1, substr2);
    return 0;
}