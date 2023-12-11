#include <stdio.h>
#include <stdlib.h>

#define EMPLOYEE 10
#define NAME_LENGTH 20

void input(int arr[], char *name[])
{
    for (int i = 0; i < EMPLOYEE; i++)
    {
        printf("Enter the ID of %d employee: ", i + 1);
        scanf("%d", &arr[i]);
        printf("name: ");
        name[i] = (char *)malloc(NAME_LENGTH * sizeof(char)); // 分配内存空间
        scanf("%s", name[i]);
    }

}

void selectionSort(int arr[], char *name[])
{
    for (int i = 0; i < EMPLOYEE - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < EMPLOYEE; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
            char *tempName = name[i];
            name[i] = name[min];
            name[min] = tempName;
        }
    }
}

void display(int arr[], char *name[])
{
    printf("\tId\tName\n");
    for (int i = 0; i < EMPLOYEE; i++)
    {
        printf("\t%d\t%s\n", arr[i], name[i]);
    }
}

void bisectionMethod(int arr[], char *name[])
{
    int n;
    printf("Enter the number to look for: ");
    scanf("%d", &n);
    int mid, left = 0, right = EMPLOYEE - 1;
    while (left <= right)
    {
        mid = (right + left) / 2;
        if (arr[mid] == n)
        {
            printf("%d has been founded,the name is %s\n", n, name[mid]);
            break;
        }
        else if (arr[mid] < n)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    if (left > right)
    {
        printf("%d is not on the list.\n", n);
    }
}

int main()
{
    int id[EMPLOYEE] = {0};
    char *name[EMPLOYEE] = {NULL};
    input(id, name);
    selectionSort(id,name);
    display(id,name);
    bisectionMethod(id, name);
    // 在程序结束前释放内存空间
    for (int i = 0; i < EMPLOYEE; i++) {
        free(name[i]);
    }

    return 0;
}