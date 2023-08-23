#include <stdio.h>
#include <stdlib.h>

int compare(const void *element_1,const void *element_2) 
{
    return (*(int *) element_1 - *(int *) element_2);
}

int main()
{
    int area[10] = {0};
    printf("Enter the area of the 10 regions.\n");
    for (int i = 0; i < 10; ++i)
        scanf("%d", &area[i]);
    qsort(area, 10, sizeof(int),compare);
    for (int i = 0; i < 10; ++i)
        printf("%d ", area[i]);

    return 0;
}