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
