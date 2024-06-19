#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct Date
{
    int year;
    int month;
    int day;
} Date;

int days(Date newDate)
{
    const int day_tab[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int count = newDate.day;
    for (int i = 0; i < newDate.month; i++)
    {
        count += day_tab[i];
    }

    if (newDate.month > 2 && ((!(newDate.year % 4) && newDate.year % 100) || !(newDate.year % 400)))
    {
        count += 1;
    }

    return count;
}

int main()
{
    Date nowadays;

    printf("年: ");
    scanf("%d", &nowadays.year);

    printf("月: ");
    scanf("%d", &nowadays.month);

    printf("日: ");
    scanf("%d", &nowadays.day);

    printf("第%d天。\n", days(nowadays));

    return 0;
}