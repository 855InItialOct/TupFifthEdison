#include <stdio.h>
int main()
{
	const char *a = "I love China!";
	a = a + 7;
	printf("%s\n", a);
	return 0;
}
