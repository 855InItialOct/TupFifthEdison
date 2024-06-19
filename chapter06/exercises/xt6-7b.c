#include <stdio.h>

int main()
{
    int cube[3][3] = {{0}};
    int row, col, nextRow, nextCol, num;

    row = 0;
    col = 3 / 2;
    nextRow = row;
    nextCol = col;
    num = 1;

    while (num < 10)
    {
        cube[row][col] = num;
        nextRow = (0 == nextRow ? 3 - 1 : nextRow - 1);
        nextCol = (nextCol + 1) % 3;
        if (0 != cube[nextRow][nextCol] || (0 == row && 3 - 1 == col))
        {
            nextRow = row + 1;
            nextCol = col;
        }
        row = nextRow;
        col = nextCol;
        num++;
    }

    for (row = 0; row < 3; row++)
    {
        for (col = 0; col < 3; col++)
        {
            printf("%4d", cube[row][col]);
        }
        printf("\n");
    }

    return 0;
}