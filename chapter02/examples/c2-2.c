#include <stdio.h>

int main()
{
    int i = 1, ni = 0, gi = 0;
    
    while (i <= 50)
    {
        scanf("%d %d", &ni, &gi);
        if (gi >= 80)
            printf("id:%d score:%d\n", ni, gi);
        i=i+1;
    }

    return 0;
}
