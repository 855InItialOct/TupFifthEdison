//判断2000——2500年中的每一年是否为闰年，并将结果输出。

#include <stdio.h>

int main()
{
    int year = 2000;

    while (year <= 2500)
    {
        if (0 == year % 4 && 0 != year % 100)
            printf("%d is a leap year.\n",year);
        else if (0 == year % 400)
            printf("%d is a leap year.\n",year);
        else
            printf("%d is not a leap year.\n",year);
        year=year+1;
    }

    return 0;
}
