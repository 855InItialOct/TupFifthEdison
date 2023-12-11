#include <stdio.h>

int main() 
{
    int legendre(int, int);
    int a, b;
    printf("Enter n and x:\n");
    scanf("%d %d", &a, &b);
    printf("legendre is %d", legendre(a, b));
    return 0;
}

int legendre(int n, int x) 
{
    int result = 0;
    if (n == 0)
        result = 1;
    else if (n == 1) {
        result = x;
    } else {
        result = ((2 * n - 1) * x - legendre((n - 1), x) * legendre((n - 2), x)) / n;
    }
    return result;
}