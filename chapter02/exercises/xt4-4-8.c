#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c, delta, p, q;

	printf("Please enter a,b and c:");
	scanf("%lf %lf %lf", &a, &b, &c);

	delta = b * b - 4 * a * c;
	p = -b / 2 * a;
	q = sqrt(delta) / 2 * a;
	if (delta > 0)
		printf("x1 = %lf,x2 = %lf\n", p - q, p + q);
	else if (0 == delta)
		printf("x1 = x2 = %lf\n", p);
	else
		printf("The equation %.1lfx²+%.1lfx+%.1lf has no real roots\n", a, b, c);

	return 0;
}
