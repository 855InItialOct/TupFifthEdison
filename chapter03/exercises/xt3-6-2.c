#include <stdio.h>
#include <ctype.h>

int main()
{
    char pwd;

    while ('\n' != (pwd = getchar()))
    {
        if (isalpha(pwd))
        {
            pwd += 4;
            if (pwd >= 90 && pwd <= 94 || pwd >= 122)
            {
                pwd -= 26;
            }
        }
        putchar(pwd);
    }

    return 0;
}