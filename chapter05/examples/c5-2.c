//用do…while语句求1+2+3+…+100，即∑_(𝑛=1)^100 𝑛

#include <stdio.h>
int main()
{
 int i=1,sum=0;
 do 
 {
   sum=sum+i;
   i++;
 }while(i<=100);
 printf("%d\n",sum);
 return 0;
}
