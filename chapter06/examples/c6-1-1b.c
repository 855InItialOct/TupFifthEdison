#include <stdio.h>

void func(int n)
{
    int a[2*n];
    //static int array[2*n];变长数组不能包含静态存储持续时间
}
int main()
{
    int n;
    scanf("%d",&n);
    func(n);

    return 0;
}
