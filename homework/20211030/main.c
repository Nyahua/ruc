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
    // ranking
    arrScore[0][2] = 1;
    for (i = 1; i < m; i++)
    {
        if (arrScore[i][1] == arrScore[i-1][1]) {
            arrScore[i][2] = arrScore[i-1][2];
        }
        else {
            arrScore[i][2] = arrScore[i-1][2] + 1;
        } 
    }
    // print array
    printf("-----------------------\n");
    for (i = 0; i < m; i++)
    {
         printf("%d: %d, %d\n", arrScore[i][0], arrScore[i][1], arrScore[i][2]);
    }
    
    printf("\n");

    return 0;
}