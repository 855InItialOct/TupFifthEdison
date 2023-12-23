#include <stdio.h>
#include <string.h>

int main()
{
    char A[] = "醋";
    char B[] = "酱油";
    char C[10];

    printf("Original:\n");
    printf("A:%s\n", A);
    printf("B:%s\n", B);

    strcpy(C,A);
    strcpy(A,B);
    strcpy(B,C);
    
    printf("Now:\n");
    printf("A:%s\n", A);
    printf("B:%s\n", B);

    return 0;
}
