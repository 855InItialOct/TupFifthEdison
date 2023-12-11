#include <stdio.h>

#define Row 3
#define Column 3

void exchange(int matrix[][Column])
{
    int i, j;
    for (i = 0; i < Row; i++)
    {
        for (j = i + 1; j < Column; j++)
        {
            matrix[i][j] = matrix[i][j]^matrix[j][i];
            matrix[j][i] = matrix[i][j]^matrix[j][i];
            matrix[i][j] = matrix[i][j]^matrix[j][i];
        }
    }
}

int main()
{
    int a[Row][Column];
    int i, j;

    printf("Please enter the elements of the matrix.\n");
    for (i = 0; i < Row; i++)
    {
        for (j = 0; j < Column; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    exchange(a);

    printf("The matrix after exchanging is:\n");
    for (i = 0; i < Row; i++)
    {
        for (j = 0; j < Column; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}