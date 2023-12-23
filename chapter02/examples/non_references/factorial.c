#include <stdio.h>

int main()
{
    int num,factorial = 1;

    printf("Enter a number:");
    scanf("%d",&num);

    printf("%d! = ",num);

    while(num)
    {
        factorial*=num;
        num--;
    }

    printf("%d\n",factorial);

    return 0;
}