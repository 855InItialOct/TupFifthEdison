#include <stdio.h>

int main()
{
    int m,n,r;

    scanf("%d %d", &m, &n);
    while ((r = m % n))
    {
        m=n;
        n=r;
    }

    printf("The greatest common divisor(gcd) is %d\n", n);

    return 0;
}