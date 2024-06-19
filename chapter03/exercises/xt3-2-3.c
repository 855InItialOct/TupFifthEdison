#include <stdio.h>
#include <math.h>

void principalAndInterest(double money)
{
    double principal, rate[] = {5.85, 4.68, 5.4, 4.14, 0.72};
    for (int i = 0; i < 5; i++)
    {
        principal = money;
        switch (i)
        {
        case 0:
            principal *= 1 + rate[i] / 100;
            printf("一次存5年期的本息和: %f\n", principal);
            break;
        case 1:
            principal *= 1 + 2 * rate[i] / 100;
            principal *= 1 + 3 * rate[i + 1] / 100;
            printf("先存2年期，到期后将本息再存3年期的本息和：%f\n", principal);
            break;
        case 2:
            principal *= 1 + 3 * rate[i] / 100;
            principal *= 1 + 2 * rate[i - 1] / 100;
            printf("先存3年期，到期后将本息再存2年期的本息和：%f\n", principal);
            break;
        case 3:
            principal *= pow(1 + rate[i] / 100, 5);
            printf("存1年期，到期后将本息再存1年期，连续存5次的本息和：%f\n", principal);
            break;
        case 4:
            principal *= pow(1 + rate[i] / 100 / 4, 4 * 5);
            printf("存活期存款，活期利息每一季度结算一次的本息和：%f\n", principal);
            break;
        default:
            break;
        }
    }
}

int main()
{
    double principal;
    printf("Principal: ");
    scanf("%lf", &principal);
    principalAndInterest(principal);

    return 0;
}