#include <stdio.h>

int main()
{
    int array[10], temp = 0, min = 0;

    printf("Please enter 10 integers:");

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("\nOriginal:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }

    for (int i = 0; i < 10 - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < 10; j++)
        {
            if (array[min] > array[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }

    printf("\nNow:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}