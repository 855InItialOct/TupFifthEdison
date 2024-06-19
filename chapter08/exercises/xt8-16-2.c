#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char *str;
    str = (char *)malloc(100 * sizeof(char));
    if (fgets(str, 100, stdin))
    {
        char *find = strchr(str, '\n');
        if (find)
        {
            *find = '\0';
        }
    }

    int a[10] = {0};
    int i = 0;
    char *began, *end;
    began = end = str;
    while (end < str + strlen(str) + 1)
    {
        if (isdigit(*end) && !isdigit(*began))
        {
            began = end;
        }
        else if (!isdigit(*end) && isdigit(*began))
        {
            for (char *p = began; p < end; p++)
            {
                a[i] = a[i] * 10 + (*p - '0');
            }
            i++;
            began = end;
        }
        end++;
    }

    for (i = 0; i < 10; i++)
    {
        printf("%-8d", a[i]);
    }

    free(str);

    return 0;
}
