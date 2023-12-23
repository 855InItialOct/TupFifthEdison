#include <stdio.h>
#include <math.h>

void greater_than_zero(double a, double b, double disc)
{
    printf("two different roots: %f and %f\n", -b + sqrt(disc) / 2 * a, -b - sqrt(disc) / 2 * a);
}

void equal_to_zero(double a, double b)
{
    printf("one root: %f\n", -b / 2 * a);
}

void less_than_zero(double a, double b, double disc)
{
    printf("two Conjugate complex roots %fi and %fi\n", -b + sqrt(-disc) / 2 * a, -b - sqrt(-disc) / 2 * a);
}

int main()
{
    double a, b, c, disc;

    printf("Please enter the value of the quadratic coefficient.\n");
    while (1)
    {
        scanf("%lf", &a);
        if (0 != a)
            break;
        printf("The quadratic coefficient can not be 0,please enter a non-zero value.\n");
    }

    printf("Please enter the value of the linear coefficient.\n");
    scanf("%lf", &b);
    printf("Please enter the value of the constant.\n");
    scanf("%lf", &c);

    printf("The quadratic equation has ");

    disc = b * b - 4 * a * c;
    if (disc > 0)
    {
        greater_than_zero(a, b, disc);
    }
    else if (disc == 0)
    {
        equal_to_zero(a, b);
    }
    else
    {
        less_than_zero(a, b, disc);
    }

    return 0;
}