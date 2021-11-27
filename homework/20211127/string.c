#include <stdio.h>
#include <string.h>
int main()
{
    char name[] = "zhang san";
    printf("3rd char: %c\n", name[3]);
    printf("3rd char: %c\n", name[strlen(name)]);
    printf("3rd char: %d\n", name[strlen(name)]);

    printf("address of name[0]: %p\n", &name[0]);
    printf("address of name: %p\n", name);

    printf("address of name[3]: %p\n", &name[3]);
    printf("address of name+3: %p\n", name + 3);
    printf("value of *(name+3): %c\n",*( name + 3));

    int l[] = {1, 2, 3, 4, 5};
    printf("l[2]: %d\n", l[2]);
    printf("value of *(l+2): %d\n",*( l + 2));

    printf("l %p\n", l);
    printf("l+1 %p\n", l+1);
    // printf("l+1 %p\n", l++);

    int *pl = l;
    printf("l[0] adress: %p\n", &l[0]);
    printf("pl %p\n", pl);

    char *pCh = name;
    while (*pCh) {
        printf("%c", *pCh);
        pCh++;
    }
    printf("\n");

}