#include <stdio.h>

int main()
{
    short s[1][2]={0,1};
    int a[2][5]={1,2,3,4,5,6,7,8,9,10};
    float f[3][4]={{1.414},{2.718},{3.14159}};
    // double d[][0]={9.8};
    
    printf("%hd\n",s[0][0]);
    // printf("%.f",d[0][0]);
    
    return 0;
}