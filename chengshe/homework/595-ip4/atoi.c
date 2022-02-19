#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isnotip(char ip[])
{
    // return 0;
    if (ip[0] == '0' && ip[1] == '0')
        return 1;
    if (atoi(ip) > 255)
        return 1;
    return 0;
}

int main()
{
    char input[5];
    scanf("%s", input);
    printf("number: %d", atoi(input) + 11);
}