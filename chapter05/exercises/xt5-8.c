//输出所有的“水仙花数”,所谓“水仙花数”是指一个3位数,其各位数字立方和等于该数本身。例如,153是水仙花数,因为153=1*+5*+3。

#include <stdio.h>
int main()
 {
  int i,j,k,n;
  printf("parcissus numbers are ");
  for (n=100;n<1000;n++)
   {
    i=n/100;
    j=n/10-i*10;
    k=n%10;
    if (n==i*i*i + j*j*j + k*k*k)
      printf("%d ",n);
   }
  printf("\n");
  return 0;
  }