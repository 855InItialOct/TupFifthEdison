#include <stdio.h>

int main()
{
    int sign = 1;                       //用sign代表当前项的数值符号
    double term;                        //term代表当前项的值
    double sum = 1;                     //sum代表累加和
    int deno = 2;                       //deno代表当前项的分母

    while (deno <= 100)
    {
        sign = (-1) * sign;
        term = sign * (1.0 / deno);
        sum = sum + term;
        deno = deno + 1;
    }

    printf("sum = %lf\n", sum);

    return 0;
}
