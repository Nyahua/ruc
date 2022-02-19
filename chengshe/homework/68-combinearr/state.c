#include <stdio.h>
int main()
{
    int state[10] = {0};
    for (int i = 0; i < 10; i++)
        printf("%d, ", state[i]);
    puts("");

     int unstate[10] = {1};
    for (int i = 0; i < 10; i++)
        printf("%d, ", unstate[i]);
    puts("");
}