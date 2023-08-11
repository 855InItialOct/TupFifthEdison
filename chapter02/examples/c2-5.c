//给出一个大于或等于3的正整数，判断它是不是一个素数。

#include <stdio.h>

int main()
{
    int n, flag = 1;

    scanf("%d",&n);

    int i = 2;
    while (i < n)
    {
        int r = n % i;
        if (0 == r)
        {
            printf("%d is not a prime.\n",n);
            flag = 0;
        }
        i=i+1;
    }
    if (flag) 
    {
        printf("%d is a prime.", n);
    }

    return 0;
}
