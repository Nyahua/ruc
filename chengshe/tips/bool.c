#include <stdio.h>

int main() {
    const _Bool TRUE=1, FALSE=0;
    int i=0;
    while (TRUE) {
        printf("%i\n", i);
        i++;
        if (i > 3) {return 0;} 
    }
}