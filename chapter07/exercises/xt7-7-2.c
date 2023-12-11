#include <stdio.h>
#include <ctype.h>

int isVowel(char c)
{
    if(isupper(c))
    {
        c = tolower(c);
    }
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void copyVowel(char dest[], char src[])
{
    int i = 0;
    while (src[i]!= '\0')
    {
        if (isVowel(src[i]))
        {
            dest[i] = src[i];
        }
        i++;
    }
    dest[i] = '\0';
}

int main()
{
    char src[100];
    char dest[100];
    printf("Enter another string: ");
    scanf("%s", src);
    copyVowel(dest, src);
    printf("%s\n", dest);
    return 0;
}