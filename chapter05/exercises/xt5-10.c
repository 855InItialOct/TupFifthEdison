//有一个分数序列2/1,3/2,5/3,8/5,13/8,25/13，求出这个数列的前20项之和。

#include <stdio.h> 
int main()
 {
  int i,n=20;
  double a=2,b=1,s=0,t;
  for (i=1;i<=n;i++)
   {
   s=s+a/b;
   t=a,
   a=a+b,
   b=t;
   }
   printf("sum=%16.10f\n",s);
   return 0;
   }