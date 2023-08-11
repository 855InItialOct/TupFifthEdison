// 依次输入10个数，要求输出其中最大的数。

#include <stdio.h>

int main()
{
    int i = 1;
    int n = 0, max = 0;

    while (i <= 10)
    {
        scanf("%d", &n);
        if (max < n) {
            max = n;
        }
        i=i+1;
    }
    
    printf("max = %d\n", max);

    return 0;
}
