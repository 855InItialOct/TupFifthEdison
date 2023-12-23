#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>

int main()
{
    char ch;

    while (scanf("%c", &ch) != EOF)
    {
        if (islower(ch))
        {
            ch = toupper(ch);
        }
        printf("%c", ch);
    }

    return 0;
}