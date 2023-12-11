#include <stdio.h>

void printDigits(int n) {
    if (n > 9) {
        function(n / 10);
    }
    printf("%d ", n % 10);
}

int main() 
{
    int number;

    printf("Enter a number:");
    scanf("%d", &number);

    printDigits(number);

    return 0;
}