#include <stdio.h>
#include <stdlib.h>

int step = 1;
void hanoi(int n, char rodFrom, char rodMiddle, char rodTo)
{
    if (n == 1)
    {
        printf("[setp %d] move plate %d# from %c to %c \n", step, n, rodFrom, rodTo);
        step++;
        return;
    }

    hanoi(n - 1, rodFrom, rodTo, rodMiddle);
    printf("[setp %d] move plate %d# from %c to %c \n", step, n, rodFrom, rodTo);
    step++;
    hanoi(n - 1, rodMiddle, rodFrom, rodTo);
}

int main()
{
    int n;
    scanf("%d", &n);

    hanoi(n, 'a', 'b', 'c');
    printf("%d", n);
    return 0;
}
