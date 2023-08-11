//求方程ax²+bx+c=0的根。分别考虑：①有两个不等的实根；②有两个相等的实根。

#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c, disc, p, q;

    printf("Please enter a,b and c:");
    scanf("%lf %lf %lf", &a, &b, &c);

    disc = b*b-4*a*c;
    p = -b / 2 * a;
    q = sqrt(disc) / 2 * a;
    if (disc > 0)
        printf("x1 = %lf,x2 = %lf\n", p - q, p + q);
    else if (0 == disc)
        printf("x1 = x2 = %lf\n", p);
    else
        printf("The equation %.1lfx²+%.1lfx+%.1lf has no real roots\n", a, b, c);
        
    return 0;
}
