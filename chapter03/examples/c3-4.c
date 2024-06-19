#include <stdio.h>
#include <math.h>

int main()
{
	// 定义各变量，均为double型
	double a, b, c, s, area;

	// 对边长a赋值
	a = 3.67;

	// 对边长b赋值
	b = 5.43;

	// 对边长c赋值
	c = 6.21;

	// 计算s
	s = (a + b + c) / 2;

	// 计算area
	area = sqrt(s * (s - a) * (s - b) * (s - c));

	// 输出三边a,b,c的值
	printf("a=%f\tb=%f\t%f\n", a, b, c);

	// 输出面积area的值
	printf("area=%f\n", area);

	return 0;
}