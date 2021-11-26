#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char A[] = "Hello World!";
    const char B[] = "World";
    const char C[] = "baby";

    // to find starting point of B in A
    char *pB = strstr(A, B);
    printf("found: %p\n", pB);
    printf("head length: %li\n", pB - A);

    if (*pB) // found or not
    {
        // store the tail string
        char tail[110];
        strcpy(tail, pB + strlen(B));
        printf("tail:\t %s\n", tail);

        strcpy(pB, C); // copy from postion B
        printf("add C to A:\t %s\n", A);

        strcpy(pB + strlen(C), tail); // copy from postion +C
        printf("add tail:\t %s\n", A);

        return 1;
    }
    else
        return 0;
}