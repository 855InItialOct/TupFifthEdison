//判断一个数n能否同时被3和5整除。

#include <stdio.h>

int main()
{
    int n;

    printf("Please enter a number:");
    scanf("%d",&n);
    
    if (0 == n % 3 && 0 == n % 5) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
