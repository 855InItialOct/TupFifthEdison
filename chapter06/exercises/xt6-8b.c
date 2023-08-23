#include<stdio.h>

int main() 
{
    int arr[3][4], max, min, p, q, count = 0;

    printf("请输入二维数组元素：");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            scanf("%d", &arr[i][j]);

    printf("该二维数组元素：\n");
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 4; j++)
            printf("%4d", arr[i][j]);
        printf("\n");
    }

    for (int i = 0; i < 3; i++) 
    {
        p = 0;
        q = 0;
        max = arr[i][0];
        for (int j = 1; j < 4; j++)
            if (max < arr[i][j]) {
                max = arr[i][j];
                p = j;
            }
        min = arr[0][p];
        for (int k = 1; k < 3; k++)
            if (min > arr[k][p]) {
                min = arr[k][p];
                q = k;
            }
        if (min == max)
            printf("该二维数组鞍点为：arr[%d][%d]=%d\n", q, p, min);
        else
            count++;
    }
    if (count == 3)
        printf("该二维数组无鞍点。\n");

    return 0;
}