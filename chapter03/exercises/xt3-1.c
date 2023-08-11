//假如我国国民生产总值的年增长率为7%， 计算10年后我国国民生产总值与现在相比增长多少百分比。计算公式为p=(1+r)^n。

#include <stdio.h>
#include <math.h>

int main()
{
    float p,r,n;
    r=0.1;
    n=10;
    p=pow(1+r,n);            
    printf("p=%f\n",p);

    return 0;
}