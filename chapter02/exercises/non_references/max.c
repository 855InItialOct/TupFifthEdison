#include <stdio.h>

int main()
{
    int num, max, i = 10;

    printf("Enter 10 numbers.\n");
    scanf("%d", &num);

    max = num;

    while (--i)
    {
        scanf("%d", &num);
        if (max < num)
        {
            max = num;
        }
    }

    printf("The maximum is %d.\n", max);

    return 0;
}