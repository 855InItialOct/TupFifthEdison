#include <stdio.h>
#include <ctype.h>

int main()
{
    int c;
    
    while ('\n'!=(c=getchar()))
    {
        if(isalpha(c))
        {
            c = islower(c) ? 219 - c : 155 - c;
        }
        putchar(c);
    }

    return 0;
}