#include <stdio.h>
int main()
{
	long long fac(long long n);
	long long n;
	long long y;
	printf("input an integer number:");
	scanf("%d", &n);
	y = fac(n);
	printf("%lld!=%lld\n", n, y);
	return 0;
}

long long fac(long long n)
{
	long long f = 0;
	if (n < 0)
		printf("n<0,data error!");
	else if (n == 0 || n == 1)
		f = 1;
	else
		f = fac(n - 1) * n;
	return (f);
}
