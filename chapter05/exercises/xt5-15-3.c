#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, f1, f2, f3;

    a = -10;
    b = 10;

    do 
    {
        f1 = a * (a * (2 * a - 4) + 3) - 6;
        f2 = b * (b * (2 * b - 4) + 3) - 6;
    } while ((f1 * f2) > 0);

    do 
    {
        c = (a + b) / 2;
        f3 = c * (c * (2 * c - 4) + 3) - 6;
        if (f3 * f1 < 0) 
        {
            b = c;
            f2 = f3;
        } else 
        {
            a = c;
            f1 = f3;
        }
    } while (fabs(f3) >= 1e-5);

    printf("x ≈ %6.2f\n", c);
    
    return 0;
}