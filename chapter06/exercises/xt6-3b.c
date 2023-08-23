#include <stdio.h>
#
int main()
{
    int matrix[3][3], sum = 0;

    printf("Please enter the elements of this 3 by 3 matrix.\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i==j||2==i+j)
            {
                sum += matrix[i][j];
            }
        }
    }
    
    printf("The sum of the diagonal elements of this 3X3 matrix is %d.\n", sum);

    return 0;
}