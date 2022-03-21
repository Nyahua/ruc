#include <stdio.h>
#define BOOK_NUM 5
#define PERSON_NUM 5

int take[BOOK_NUM];
int like[PERSON_NUM][BOOK_NUM] = {
    {0, 0, 1, 1, 0},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 0, 1},
    {0, 0, 0, 1, 0},
    {0, 1, 0, 0, 1},
};
int book[5] = {1, 1, 1, 1, 1}; // book[m] avaible nums
int n = 0;                     // plan num

// assing book to person i)
void assign(int i)
{
    for (int j = 0; j < BOOK_NUM; j++)
    {
        if (like[i][j] && book[j])
        {
            take[i] = j;
            book[j]--;
        }
        
        if (i == PERSON_NUM - 1)
        {
            n++;
            printf("Plan #%d:\n", n);
            for (int k = 0; k < BOOK_NUM; k++)
                printf("\tBook %d to Person %c\n", take[k], k + 65);
        }
        else
            assign(i + 1);
        take[i] = -1;
        book[j]++;
    }
}

int main()
{
    assign(0);
}