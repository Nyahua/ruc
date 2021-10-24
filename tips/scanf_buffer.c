// Problem with scanf() when there is fgets()/gets()/scanf() after it
// https://www.geeksforgeeks.org/problem-with-scanf-when-there-is-fgetsgetsscanf-after-it/
// https://stackoverflow.com/questions/5918079/fgets-doesnt-work-after-scanf


// C program to demonstrate the problem when
// scanf() is used in a loop
#include<stdio.h>
  
int main()
{
    char c;
    printf("......Enter q to quit......\n");
    do
    {
        printf("Enter a character\n");
        scanf("%c", &c);
        getchar();
        printf("%c\n", c);
    }
    while (c != 'q');
    return 0;
}