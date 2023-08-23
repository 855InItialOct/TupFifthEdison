#include <stdio.h>
#include<math.h>

int main()
{
    int prime[100];

    for (int i = 0; i < 100; i++)
    {
        prime[i] = i + 1;
    }
    prime[0] = 0;

    for (int i = 1; i < sqrt(100); i++)
    {
        for (int j = i+1; j < 100; j++)
        {
            if (prime[i]&&prime[j]&&!(prime[j]%prime[i]))
            {
                prime[j] = 0;
            }
        }
    }
    
    for (int i = 0; i < 100; i++)
    {
        if (prime[i])
        {
            printf("%d ", prime[i]);
        }
    }
    
    return 0;
}