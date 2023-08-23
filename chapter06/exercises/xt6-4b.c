#include <stdio.h>

int main()
{
    int n, temp, count;
    int array[10] = {0, 1, 2, 3, 4, 6, 7, 8, 9};

    count = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < count - 1; i++)
    {
        printf("%d ", array[i]);
    }
    
    printf("\nPlease enter the number to insert:");
    scanf("%d", &n);

    for (int i = 0; i < count - 1; i++)
    {
        if (n < array[i])
        {
            temp = i;
            break;
        }
    }

    for (int i = count - 1; i >= temp; i--)
    {
        array[i + 1] = array[i];
    }

    array[temp] = n;

    for (int i = 0; i < count; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}