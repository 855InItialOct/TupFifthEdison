#include <stdio.h>

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1; 
    }
    return 0; 
}

int getDayOfYear(int year, int month, int day) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayOfYear = 0;
    
    for (int i = 0; i < month - 1; i++) {
        dayOfYear += daysInMonth[i];
    }
    
    dayOfYear += day;
    
    if (month > 2 && isLeapYear(year)) {
        dayOfYear += 1; // 闰年的2月多一天
    }
    
    return dayOfYear;
}

int main() {
    int year, month, day;
    printf("请输入年份：");
    scanf("%d", &year);
    printf("请输入月份：");
    scanf("%d", &month);
    printf("请输入日期：");
    scanf("%d", &day);
    
    int dayOfYear = getDayOfYear(year, month, day);
    printf("该日是该年的第%d天。\n", dayOfYear);
    
    return 0;
}