#include <stdio.h>

void strcat(char buf[], char sep[])
{
    int i = 0, j = 0;
    while (buf[i++]!= '\0')
        ;
    while(buf[i++]=sep[j++])
        ;
}

int main()
{
    char buf[100];
    char sep[100];
    printf("Please enter the text you want to concatenate.\n");
    scanf("%s", buf);
    scanf("%s", sep);
    strcat(buf, sep);
    printf("%s", buf);
    return 0;
}