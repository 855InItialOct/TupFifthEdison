#include <stdio.h>

int main()
{
	// 定义变量i的初值为1,sum的初值为0
	int i = 1, sum = 0;

	// 当i>100，条件表达式i<=100的值为假，不执行循环体
	while (i <= 100)
	{				   // 循环体开始
		sum = sum + i; // 第一次累加后，sum的值为1
		i++;		   // 加完后，i的值加1，为下次累加作准备
	}				   // 循环体结束

	// 输出1+2+3…+100的累加和
	printf("sum=%d\n", sum);

	return 0;
}