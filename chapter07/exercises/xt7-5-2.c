#include <stdio.h>

void reverse(char buf[])
{
    int i, j;
    for (i = 0, j = strlen(buf) - 1; i < j; i++, j--)
    {
        buf[i] ^= buf[j];
        buf[j] ^= buf[i];
        buf[i] ^= buf[j];
    }
}

int main()
{
    char buf[1024];

    printf("Please enter a valid string.\n");
    fgets(buf, 1024, stdin);
    
    reverse(buf);

    printf("The string stored in reverse order is %s\n", buf);

    return 0;
}