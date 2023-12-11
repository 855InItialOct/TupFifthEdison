#include <stdio.h>
#include <ctype.h>

void countCharacters(const char str[])
{
    int alpha = 0, digit = 0, space = 0, other = 0;
    for (int i = 0; str[i]!= '\0'; i++)
    {
        if (isalpha(str[i]))
        {
            alpha++;
        }
        else if (isdigit(str[i]))
        {
            digit++;
        }
        else if (isspace(str[i]))
        {
            space++;
        }
        else
        {
            other++;
        }
    }
    printf("Alpha: %d\nDigit: %d\nSpace: %d\nOther: %d\n", alpha, digit, space, other);
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    countCharacters(str);

    return 0;
}