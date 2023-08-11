// 输出1900~2000年中是闰年的年份，符合下面两个条件之一的年份是闰年：
/*
 * ①能被4整除但不能被100整除；
 * ②能被 100整除且能被400整除。
 */

#include <stdio.h>

int main()
{
    int year = 1900;
    
    while (year <= 2000) 
    {
        if (0 == year % 4 && 0 != year % 100 || 0 == year % 400)
            printf("%d ", year);
        year = year + 1;
    }
    printf("\n");

    return 0;
}
