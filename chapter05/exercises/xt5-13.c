#include <stdio.h>
#include <math.h>

int main()
{
	setbuf(stdout, NULL);
	double a, x0, x1;
	printf("Enter the number to be squared:");
	scanf("%lf", &a);
	x0 = a / 2;
	x1 = (x0 + a / x0) / 2;
	while (fabs(x1 - x0) >= 1e-5)
	{
		x0 = x1;
		x1 = (1.0 / 2) * (x0 + a / x0);
	}
	printf("The square root of %f is %f\n", a, x1);

	return 0;
}