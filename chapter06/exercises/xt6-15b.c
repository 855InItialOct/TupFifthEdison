#include <stdio.h>

int main()
{
    char str1[20] = "19981025", str2[20];

    printf("The original string is:");
    puts(str1);
    printf("Input the string to be copied.\n");
    gets(str2);

    for (int i = 0; (str1[i] = str2[i]); i++)
        ;

    printf("The copied string is %s\n", str1);

    return 0;
}