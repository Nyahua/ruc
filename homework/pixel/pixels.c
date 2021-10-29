#include <stdio.h>

int m, n; // column and row numbers
// array of pixels for R, G, B and weight(bad/not bad)
short pixelArr[4][100][100];

void scan2array()
{
    char pixString[18 * 100];
    int row, col, nchar;
    short red, green, blue;

    for (row = 0; row < n; row++)
    {
        fgets(pixString, 18 * 100, stdin);
        for (col = 0; col < m; col++)
        {
            sscanf(pixString, "R %hd G %hd B %hd %1800[^\n]",
                   &pixelArr[0][row][col], &pixelArr[1][row][col],
                   &pixelArr[2][row][col], pixString);
        }
    }
}

void assignWeight()
{
    int row, col;
    for (row = 0; row < n; row++)
    {
        for (col = 0; col < m; col++)
        {
            pixelArr[3][row][col] =
                ((pixelArr[0][row][col] == 0) && (pixelArr[1][row][col] == 0) && (pixelArr[2][row][col] == 0)) ? 0 : 1;
        }
    }
}

int haveBadPixel()
{
    int row, col;
    for (row = 0; row < n; row++)
    {
        for (col = 0; col < m; col++)
        {
            if (pixelArr[3][row][col] == 0)
            {
                return 1;
            }
        }
    }
    return 0;
}

void pixelWeight(int row, int col)
{
    int weightSum;
    weightSum = (
            ((row > 0) ? pixelArr[3][row - 1][col] : 0) 
            + ((col > 0) ? pixelArr[3][row][col - 1] : 0) 
            + ((row < n-1) ? pixelArr[3][row + 1][col] : 0) 
            + ((col < m-1) ? pixelArr[3][row][col + 1] : 0)
        );
    int color;
    for (color = 0; color < 3; color++)
    {
        // how to round up: int a = (59 + (4 - 1)) / 4;
        // https://stackoverflow.com/questions/2422712/rounding-integer-division-instead-of-truncating
        if (weightSum != 0)
        {
            pixelArr[color][row][col] =
                (int)(
                    ((row > 0) ? pixelArr[color][row - 1][col] : 0) * pixelArr[3][row - 1][col] 
                    + ((col > 0) ? pixelArr[color][row][col - 1] : 0) * pixelArr[3][row][col - 1] 
                    + ((row < n-1) ? pixelArr[color][row + 1][col] : 0) * pixelArr[3][row + 1][col] 
                    + ((col < m-1) ? pixelArr[color][row][col + 1] : 0) * pixelArr[3][row][col + 1] 
                    + (weightSum - 1)
                    ) / weightSum;
        }
    }
}

void fixPixels()
{
    int row, col;
    for (row = 0; row < n; row++)
    {
        for (col = 0; col < m; col++)
        {
            if (pixelArr[3][row][col] == 0)
            {
                pixelWeight(row, col);
            }
        }
    }
}

void printArr()
{
    int row, col;
    for (row = 0; row < n; row++)
    {
        printf("|");
        for (col = 0; col < m; col++)
        {
            printf(" (%d, %d, %d, %d) |",
                   pixelArr[0][row][col], pixelArr[1][row][col],
                   pixelArr[2][row][col], pixelArr[3][row][col]);
        }
        printf("\n");
    }
}

void printArrTest()
{
    int row, col;
    for (row = 0; row < n; row++)
    {
        for (col = 0; col < m; col++)
        {
            printf("R %d G %d B %d",
                   pixelArr[0][row][col], pixelArr[1][row][col],
                   pixelArr[2][row][col]);
            if (col != (m-1)) {
                printf(" ");
            }
            else {
                printf("\n");
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    getchar();
    scan2array();
    assignWeight();
    while (haveBadPixel())
    {
        fixPixels();
        assignWeight();
    }
    printArrTest();

    return 0;
}