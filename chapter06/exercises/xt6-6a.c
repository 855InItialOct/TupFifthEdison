#include <stdio.h>
#define N 10
int main()
{
    int triangle[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (0 == j || j == i)
            {
                triangle[i][j] = 1;
            }
            else
            {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("%6d ", triangle[i][j]);
        }
        printf("\n");
    }

    return 0;
}