//将100~200之间的素数输出。

#include <stdio.h>
#include <math.h>

int main()
{
    int n=100;

    while (n <= 200)
    {
        int i = 2, flag = 1;
        while (i <= sqrt(n))
        {
            if (0 == n % i)
            {
                flag = 0;
                break;
            }
            i = i + 1;
        }
        if (flag)
            printf("%d ", n);
        n = n + 1;
    }
    printf("\n");

    return 0;
}
