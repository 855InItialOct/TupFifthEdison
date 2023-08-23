#include <stdio.h>

int main()
{
    int s = 1, h;

    printf("Enter the number of the lines print:");
    scanf("%d", &h);
    printf("1\n");
    for (int i = 2; i < h; ++i, s = 1) {
        printf("1 ");
        for (int j = 1; j < i - 1; ++j) {
            printf("%d ", (s = (i - j) * s/ j));
        }
        printf("1\n");
    }

    return 0;
}