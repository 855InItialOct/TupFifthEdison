#include <stdio.h>

int main()
{
    char s1[80], s2[40];
	int i = 0, j = 0;
	printf("input string1:");
	scanf("%s", s1);
	printf("input string2:");
	scanf("%s", s2);
    
    while ('\0'!=s1[i++])
        ;
    while (s1[i++]=s2[j++])
        ;

    printf("\nThe new string is:%s\n", s1);

    return 0;
}