//有一阶跃函数：
/*
   −1  (𝑥<0)
y={ 0  (𝑥=0)
    1  (𝑥>0)
编一程序,输入一个x值，要求输出相应的y值。
*/

#include <stdio.h>
int main()
{
  int x,y;
  scanf("%d",&x);
  if(x<0)
    y=-1;
  else 
    if(x==0) y=0;
    else y=1;
  printf("x=%d,y=%d\n",x,y);
  return 0;
}