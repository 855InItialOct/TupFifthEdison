#include <stdio.h>
int main()
{
	int result;
	char str1[100], str2[100];
	printf("input string1:");
	gets(str1);
	printf("\ninput string2:");
	gets(str2);

	for (int i = 0; !(result = str1[i] - str2[i]) && '\0' != str1[i]; i++)
	{
	}

	printf("\n%d\n", result);

	return 0;
}
