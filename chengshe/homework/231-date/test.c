#include <stdio.h>
#include <string.h>

int charType(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    else if (c >= 'A' & c <= 'z')
        return -1;
    else
        return 0;
}

int main(){
    printf("%d\n", charType('z'));
}