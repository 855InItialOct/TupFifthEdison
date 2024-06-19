#include <stdio.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100
#define MAX_NUMBERS 100

int main()
{
    char input[MAX_INPUT_LENGTH];
    int numbers[MAX_NUMBERS];
    int numNumbers = 0;

    printf("请输入一个字符串：");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    int i = 0;
    while (input[i] != '\0')
    {
        if (isdigit(input[i]))
        {
            int number = input[i] - '0';
            i++;
            while (isdigit(input[i]))
            {
                number = number * 10 + input[i] - '0';
                i++;
            }
            numbers[numNumbers] = number;
            numNumbers++;
        }
        else
        {
            i++;
        }
    }

    printf("共有%d个整数：\n", numNumbers);
    for (int j = 0; j < numNumbers; j++)
    {
        printf("%d ", numbers[j]);
    }
    printf("\n");

    return 0;
}