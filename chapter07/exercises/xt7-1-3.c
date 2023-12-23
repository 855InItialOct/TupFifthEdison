#include <stdio.h>

int main(void)
{
    int gcd(int, int);
    int m, n, d;

    printf("Please enter m and n;\n");
    scanf("%d %d", &m, &n);

    d = gcd(m, n);

    printf("The greatest common divisor of %d and %d is %d.\n", m, n, d);
    printf("The lowest common multiple of %d and %d is %d.\n", m, n, m * n / d);

    return 0;
}

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}