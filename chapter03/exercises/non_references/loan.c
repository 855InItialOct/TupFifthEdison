#include <stdio.h>
#include <math.h>

int main()
{
    int principal, payment;
    double rate, time;

    printf("Enter the principal amount: ");
    scanf("%d", &principal);
    printf("Enter the monthly payment: ");
    scanf("%d", &payment);
    printf("Enter the rate of interest: ");
    scanf("%lf", &rate);

    time = log10(payment / (payment - principal * rate)) / log10(1.0 + rate);

    printf("Time required to repay the loan: %.1f years\n", time);

    return 0;
}