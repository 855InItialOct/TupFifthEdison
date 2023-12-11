#include <stdio.h>
#include <ctype.h>

void print_longest_word(const char str[])
{
    int i, j;
    int len = 0;
    int max = 0;
    for (i = 0; str[i]!= '\0'; i++)
    {
        if (isalpha(str[i]))
        {
            len++;
        }
        else
        {
            if (len > max)
            {
                max = len;
                j = i;
            }
            len = 0;
        }
    }
    printf("The longest word is:");
    for (i = j - max; i < j; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main()
{
    char buf[1024];
    printf("Please enter a string.\n");
    fgets(buf, 1024, stdin);
    
    print_longest_word(buf);

    return 0;
}