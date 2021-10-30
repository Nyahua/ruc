#include <stdio.h>

int main()
{
    // input tishu(n), tiahao[n], students(m), output rank(k)
    int n, m, k;
    scanf("%d", &n);
    int i, j, tihao[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &tihao[i]);
    }
    scanf("%d %d", &m, &k);
    // input students num, tishu(p), and score
    int stdNum, p, score;

    //m stdudents in rows, stdNum, scores and rank in col
    int arrScore[m][3];
    for (i = 0; i < m; i++)
    { // loop for m students
        scanf("%d %d", &stdNum, &p);
        arrScore[i][0] = stdNum;

        // loop for p tihao and caculate score
        score = 0;
        for (j = 0; j < p; j++)
        {
            int myTihao; // tihao done by this student
            scanf("%d", &myTihao);
            // check if myTihao is in tihao[n]
            int tihaoNum;
            for (tihaoNum = 0; tihaoNum < n; tihaoNum++)
            {
                if (tihao[tihaoNum] == myTihao)
                {
                    score++;
                }
            }
        }
        arrScore[i][1] = score;
        arrScore[i][2] = 1;
        // bubble this student
        int rowNum = i;
        int tempStuNum, tempScore;
        while (rowNum > 0)
        {
            if (arrScore[rowNum][1] > arrScore[rowNum - 1][1])
            {
                tempStuNum = arrScore[rowNum - 1][0];
                tempScore = arrScore[rowNum - 1][1];
                arrScore[rowNum - 1][0] = arrScore[rowNum][0];
                arrScore[rowNum - 1][1] = arrScore[rowNum][1];
                arrScore[rowNum][0] = tempStuNum;
                arrScore[rowNum][1] = tempScore;
                arrScore[rowNum][2] = arrScore[rowNum - 1][2] + 1;
            }
            if (arrScore[rowNum][1] == arrScore[rowNum - 1][1] & arrScore[rowNum][0] < arrScore[rowNum - 1][0])
            {
                tempStuNum = arrScore[rowNum - 1][0];
                tempScore = arrScore[rowNum - 1][1];
                arrScore[rowNum - 1][0] = arrScore[rowNum][0];
                arrScore[rowNum - 1][1] = arrScore[rowNum][1];
                arrScore[rowNum][0] = tempStuNum;
                arrScore[rowNum][1] = tempScore;
            }
            rowNum--;
        }
    }

    // printf("%d students, %d ranks", m, k);
    printf("-----------------------\n");
    for (i = 0; i < m; i++)
    {
        printf("%d: %d\n", arrScore[i][0], arrScore[i][1]);
    }
    printf("\n");

    return 0;
}