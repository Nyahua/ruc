// Never apply an indirection operator to an uninitialized pointer. Doing so, invoke undefined behavior.
// https://www.geeksforgeeks.org/core-dump-segmentation-fault-c-cpp/
// https://stackoverflow.com/questions/26082081/segmentation-fault-core-dumped-when-assigning-char-to-char-pointer

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p;
    printf("pointer address %p\n", p); // <- (nil)
    // *p = 1; //Segmentation fault (core dumped)

    p = malloc(sizeof(int));
    *p = 1;
    printf("pointer address %p\n", p);

    free(p); //always free assigned memory

    return 0;
}
