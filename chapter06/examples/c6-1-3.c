#include <stdio.h>

int main()
{
    short s[3]={1,2,3};
    int a[10]={1,2,3,4,5};
    float f[3]={0};
    double d[]={0};

    printf("%.2f\n",d[0]);
    
    long l[2];
    for (int i = 0; i < 2; i++)
    {
        /* code */
        printf("%d ",l[i]);
    }
    printf("\n");

    return 0;
}