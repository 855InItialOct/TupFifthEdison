#include <stdio.h>
#include <math.h>
int main()
{
	float integral(float (*)(float), float, float, int);
	float f_sin(float);
	float f_cos(float);
	float f_exp(float);
	float a1, b1, a2, b2, a3, b3, c, (*p)(float);
	int n = 20;
	printf("input a1,b1:");
	scanf("%f,%f", &a1, &b1);
	printf("input a2,b2:");
	scanf("%f,%f", &a2, &b2);
	printf("input a3,b3:");
	scanf("%f,%f", &a3, &b3);
	p = f_sin;
	c = integral(p, a1, b1, n);
	printf("The integral of sin(x) is:%f\n", c);
	p = f_cos;
	c = integral(p, a2, b2, n);
	printf("The integral of cos(x) is:%f\n", c);
	p = f_exp;
	c = integral(p, a3, b3, n);
	printf("The integral of exp(x) is:%f\n", c);
	return 0;
}

float integral(float (*p)(float), float a, float b, int n)
{
	int i;
	float x, h, s;
	h = (b - a) / n;
	x = a;
	s = 0;
	for (i = 1; i <= n; i++)
	{
		x = x + h;
		s = s + (*p)(x)*h;
	}
	return (s);
}
float f_sin(float x)
{
	return sin(x);
}
float f_cos(float x)
{
	return cos(x);
}
float f_exp(float x)
{
	return exp(x);
}
