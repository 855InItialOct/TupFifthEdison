#include <stdio.h>

// 定义主函数
int main()
// 主函数体开始
{
	// 对被调用函数max的声明
	int max(int x, int y);

	// 定义变量a，b，c
	int a, b, c;

	// 输入变量a和b的值
	scanf("%d,%d", &a, &b); 

	// 调用max函数，将得到的值赋给c
	c = max(a, b);

	// 输出c的值
	printf("max=%d\n", c);

	// 返回函数值为0
	return 0;
}

// 定义max函数,函数值为整型, 形式参数x和y为整型
int max(int x, int y)
{
	// max函数中的声明部分，定义本函数中用到的变量z为整型
	int z;

	if (x > y)
		z = x;
	else
		z = y;

	// 将z的值返回，通过max带回到调用函数的位置
	return (z); 
}
