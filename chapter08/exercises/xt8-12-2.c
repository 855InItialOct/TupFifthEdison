#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void selectionSort(char **src, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        char **p = src + i;
        for (int j = i + 1; j < n; j++)
        {
            if (0 < strcmp(*p, *(src + j)))
            {
                p = src + j;
            }
        }
        if (p != src + i)
        {
            char *t = *(src + i);
            *(src + i) = *p;
            *p = t;
        }
    }
}

void output(char **src, int n)
{
    putchar(10);
    for (int i = 0; i < n; i++)
    {
        puts(*(src + i));
    }
}

void my_gets(char **dest, int n)
{
    for (int i = 0; i < n;)
    {
        dest[i] = (char *)malloc(20 * sizeof(char));
        if (fgets(dest[i], 20, stdin))
        {
            // 去掉空格、制表符或换行符
            if (isspace(*dest[i]))
            {
                continue;
            }
            char *find = strchr(dest[i], '\n');
            if (find)
            {
                *find = '\0';
            }
            i++;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n > 0)
    {
        char *str[n];
        my_gets(str, n);
        // output(str, n);
        selectionSort(str, n);
        output(str, n);
    }

    return 0;
}
