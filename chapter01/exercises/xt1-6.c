//编写一个C程序，运行时输入a,b,c三个值，输出其中最大值。

#include <stdio.h>

int main()
{
  int a,b,c,max;

  printf("please input a,b,c:\n");
  scanf("%d,%d,%d",&a,&b,&c);

  max=a;
  if (max<b)
    max=b;
  if (max<c)
    max=c;

  printf("The largest number is %d\n",max);

  return 0;
}
