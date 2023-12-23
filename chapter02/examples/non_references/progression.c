#include <stdio.h>

#define N 100

int main()
{
	double sum = 0;

	for (int i = 1; i <= N; i++)
	{
		sum += (0 == i % 2) ? -1.0 / i : 1.0 / i;
	}

	printf("%lf\n", sum);

	return 0;
}