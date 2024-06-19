#include <stdio.h>
int main()
{
	const char string[] = "I love China!";
	printf("%s\n", string); // 用%s输出strung，可以输出整个字符串
	printf("%c\n", string[7]);
	return 0;
}
