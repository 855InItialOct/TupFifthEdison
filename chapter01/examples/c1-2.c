// 这是编译预处理命令
#include <stdio.h>

// 定义主函数
int main()
// 函数开始
{
	// 本行是程序的声明部分，定义a、b、sum为整型变量
	int a, b, sum; 

	// 对变量a赋值
	a = 123;

	// 对变量b赋值
	b = 456;

	// 进行a+b 的运算，并把结果存放在变量sum中
	sum = a + b;

	// 输出结果
	printf("sum is %d\n", sum);

	// 使函数返回值为0
	return 0;
}
// 函数结束
