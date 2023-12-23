#include <stdio.h>
#include <math.h>

int main()
{
    int num, flag = 0;

    printf("Enter a integer greater than or equal to 3.\n");
    while (scanf("%d", &num) != EOF)
    {
        if (num < 3)
        {
            printf("Input error,please retype.\n");
        }
        else
        {
            for (int i = 2; i <= sqrt(num); i++)
            {
                if (0 == num % i)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
            {
                printf("%d is not a prime.\n", num);
            }
            else
            {
                printf("%d is a prime.\n", num);
            }
        }
    }

    return 0;
}