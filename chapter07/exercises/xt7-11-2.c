#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 11

void sort(char str[],int number) {
    int i, j;
    char t;
    for (j = 0; j < number - 1; j++)
    {
        for (i = 0; i < number - j - 1; i++)
        {
            if (str[i] > str[i + 1])
            {
                t = str[i];
                str[i] = str[i + 1];
                str[i + 1] = t;
            }
        }
    }
}

int main() 
{
    int num = 0;
    char c;
    char buf[N];
    printf("请输入多个字符：");
    // fgets(buf, sizeof(buf), stdin);
    // strtok(buf, " \t\r\n");

    while ((c = getchar())!= '\n' && num < N-1)
    {
        if (isalpha(c))
            buf[num++] = c;
    }
    buf[num] = '\0';
    printf("输入的前10个字符为：%s\n", buf);
    sort(buf,num);
    printf("排序后的字符顺序为：%s\n", buf);
    return 0;
}