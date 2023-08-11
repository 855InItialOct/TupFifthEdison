//企业发放的奖金根据利润提成。
/*
利润I低于或等于100000元的,奖金可提成10%；
利润高于100000元，低于200000元(1000001000000时,
超过1000000元的部分按1%提成。
从键盘输入当月利润I,求应发奖金总数。
要求：(1) 使用if语句编写程序。(2) 使用switch语句编写程序。
*/

#include <stdio.h>
int main()
{
  int i;
  double bonus,bon1,bon2,bon4,bon6,bon10;
  bon1=100000*0.1;
  bon2=bon1+100000*0.075;
  bon4=bon2+100000*0.05;
  bon6=bon4+100000*0.03;
  bon10=bon6+400000*0.015;
  printf("请输入利润i:");
  scanf("%d",&i);
  if (i<=100000)
     bonus=i*0.1;
  else if (i<=200000)
     bonus=bon1+(i-100000)*0.075;
  else if (i<=400000)
     bonus=bon2+(i-200000)*0.05;
  else if (i<=600000)
     bonus=bon4+(i-400000)*0.03;
  else if (i<=1000000)
     bonus=bon6+(i-600000)*0.015;
  else
     bonus=bon10+(i-1000000)*0.01;
  printf("奖金是: %10.2f\n",bonus);
  return 0;
 }
 