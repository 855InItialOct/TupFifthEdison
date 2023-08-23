#include <stdio.h>
int main()
{
	int i, result;
	char s1[100], s2[100];
	printf("input string1:");
	gets(s1);
	printf("\ninput string2:");
	gets(s2);
	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0'))
		i++;
	if (s1[i] == '\0' && s2[i] == '\0')
		result = 0;
	else
		result = s1[i] - s2[i];
	printf("\nresult:%d.\n", result);
	return 0;
}
