#include <stdio.h>

int isPrime(int x)
{
    int i;
    for (i = 2; i < x; i*=i)
        if (x % i == 0)
            return 0;
    return 1;
}

int main()
{
    int n;

    printf("Please enter a integer number.\n");
    while(scanf("%d", &n)!= EOF) 
    {
        if (isPrime(n))
            printf("%d is a prime number.\n", n);
        else
            printf("%d is not a prime number.\n", n); 
    }

    return 0;
}