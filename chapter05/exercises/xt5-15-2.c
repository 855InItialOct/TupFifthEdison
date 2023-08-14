#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, fa, fb, fc;

    do 
    {
        printf("Please enter the range of the interval:");
        scanf("%lf %lf", &a, &b);
        fa = a * (a * (a * 2 - 4) + 3) - 6;
        fb = b * (b * (b * 2 - 4) + 3) - 6;
    } while ((fa * fb) > 0);

    do 
    {
        c = (a + b) / 2;
        fc = c * (c * (c * 2 - 4) + 3) - 6;
        if ((fc * fa )< 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    } while (fabs(fc) >= 1e-5);
    
    printf("The root of the function in the interval is %f\n", c);

    return 0;
}