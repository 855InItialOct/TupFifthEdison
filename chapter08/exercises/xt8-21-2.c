#include <stdio.h>
#include <stdlib.h>

void sortIntegers(int **numbers, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (*numbers[j] > *numbers[j + 1])
            {
                int *temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("请输入整数的个数：");
    scanf("%d", &n);

    int **numbers = (int **)malloc(n * sizeof(int *));
    printf("请输入%d个整数：\n", n);
    for (int i = 0; i < n; i++)
    {
        numbers[i] = (int *)malloc(sizeof(int));
        scanf("%d", numbers[i]);
    }

    sortIntegers(numbers, n);

    printf("排序后的整数：\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *numbers[i]);
        free(numbers[i]);
    }
    free(numbers);

    return 0;
}