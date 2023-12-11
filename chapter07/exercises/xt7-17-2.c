#include <stdio.h>

void ItoC(int number) 
{
    if (number > 9) {
        ItoC(number / 10);
    }
    putchar(number % 10 + '0');
    putchar(32);
}

//相似的方法
void intToString(int num) {
    if (num / 10 != 0) {
        intToString(num / 10);
    }
    printf("%c", '0' + num % 10);
}

int main() 
{
    int n;

    printf("Input an integer:");
    scanf("%d", &n);
    
    if (n < 0) {
    //  puts("- ");会自动换行，不推荐。
        putchar('-');
        putchar(' ');
        n = -n;
    }
    
    ItoC(n);

    return 0;
}
