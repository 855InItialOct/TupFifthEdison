#include <stdio.h>

void countCharacters(const char *str, int *letters, int *digits, int *spaces, int *others)
{
    *letters = *digits = *spaces = *others = 0;

    while (*str)
    {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
        {
            (*letters)++;
        }
        else if (*str >= '0' && *str <= '9')
        {
            (*digits)++;
        }
        else if (*str == ' ')
        {
            (*spaces)++;
        }
        else
        {
            (*others)++;
        }

        str++;
    }
}

int main()
{
    char str[100];
    int letters, digits, spaces, others;

    printf("请输入一个字符串：");
    fgets(str, sizeof(str), stdin);

    countCharacters(str, &letters, &digits, &spaces, &others);

    printf("字母个数：%d\n", letters);
    printf("数字个数：%d\n", digits);
    printf("空格个数：%d\n", spaces);
    printf("其他字符个数：%d\n", others);

    return 0;
}