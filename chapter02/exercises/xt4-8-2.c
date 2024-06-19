#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c, delta, x1, x2, realPart, imagePart;

	printf("Please enter a,b and c:");
	scanf("%lf %lf %lf", &a, &b, &c);
	printf("The equation ");

	if (fabs(a) <= 1e-6)
	{
		printf("is not a quadratic.\n");
	}
	else
	{
		delta = b * b - 4 * a * c;
		if (fabs(delta) <= 1e-6)
			printf("has two equal roots:%8.4f\n", -b / (2 * a));
		else if (delta > 1e-6)
		{
			x1 = (-b + sqrt(delta)) / (2 * a);
			x2 = (-b - sqrt(delta)) / (2 * a);
			printf("has distinct real roots:%8.4f and %8.4f\n", x1, x2);
		}
		else
		{
			realPart = -b / (2 * a);
			imagePart = sqrt(-delta) / (2 * a);
			printf("has complex roots:\n");
			printf("%8.4f+%8.4fi\n", realPart, imagePart);
			printf("%8.4f-%8.4fi\n", realPart, imagePart);
		}
	}

	return 0;
}
