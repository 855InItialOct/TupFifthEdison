#include <stdio.h>

void printDigits(int num)
{
    int divisor;
    num = fabs(num);
    for (divisor = 1; num / divisor >= 10;divisor*= 10)
        ;
    while(divisor)
    {
        printf("%d ", num / divisor);
        num %= divisor;
        divisor /= 10;
    }
}

int main()
{
    int n;

    printf("Please enter a number.\n"); 
    scanf("%d", &n);

    printDigits(n);

    return 0;
}