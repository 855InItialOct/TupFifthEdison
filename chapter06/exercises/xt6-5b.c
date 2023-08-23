#include <stdio.h>

int main()
{
    int array[] = {8, 6, 5, 4, 1}, count = 5;

    for (int i = 0; i < count; i++)
    {
        printf("%d ", array[i]);
    }

    for (int i = 0; i < count/2; i++)
    {
        array[i] = array[i] ^ array[count - i - 1];
        array[count - i - 1] = array[i] ^ array[count - i - 1];
        array[i] = array[i] ^ array[count - i - 1];
    }
    
    printf("\nBe reserved:\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", array[i]);
    }
    
    return 0;
}