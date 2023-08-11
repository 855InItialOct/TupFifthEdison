//用迭代法求平方根。
/*
求平方根的迭代公式为:
 Xn+1=1/2 (Xn + a/Xn)
要求前后两次求出的x的差的绝对值小于10^-5。
*/

 #include <stdio.h>
 #include <math.h>
int main()
 {
  float a,x0,x1;
  printf("enter a positive number:");
  scanf("%f",&a);
  x0=a/2;
  x1=(x0+a/x0)/2;
  do
   {x0=x1;
    x1=(x0+a/x0)/2;
   }while(fabs(x0-x1)>=1e-5);
  printf("The square root of %5.2f  is %8.5f\n",a,x1);
  return 0;
 }