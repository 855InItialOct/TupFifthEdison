#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num)
{
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    for (int num = 100; num <= 200; num++)
    {
        if (is_prime(num))
        {
            printf("%d ", num);
        }
    }
    return 0;
}
