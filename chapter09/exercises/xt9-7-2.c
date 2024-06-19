#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int Length = 10;

void input(int *pArr)
{
    for (int i = 0; i < Length; i++)
    {
        printf("element %d: ", i);
        scanf("%d", pArr + i);
    }
}

void output(const int *pArr)
{
    for (int i = 0; i < Length; i++)
    {
        printf("%-4d", *(pArr + i));
    }
}

void delBySub(int *pArr, int index)
{
    int count = Length;
    for (int i = 0, j = 0; i < count; i++)
    {
        if (index == i)
        {
            Length--;
        }
        else
        {
            *(pArr + j) = *(pArr + i);
            j++;
        }
    }
}

void delBefore(int *pArr, int index)
{
    for (int i = index, j = 0; i < Length; i++, j++)
    {
        *(pArr + j) = *(pArr + i);
    }
    Length -= index;
}

void delAfter(int *pArr, int index)
{
    for (int i = 0, j = 0; i < index + 1; i++, j++)
    {
        *(pArr + j) = *(pArr + i);
    }
    Length = index + 1;
}

void delElements(int *pArr, int num)
{
    int i = 0, j = 0, count = Length;
    for (; i < count; i++)
    {
        if (num != *(pArr + i))
        {
            *(pArr + j) = *(pArr + i);
            j++;
        }
        else
        {
            Length--;
        }
    }
}

void removeDuplicate(int *pArr)
{
    for (int i = 0; i < Length - 1; i++)
    {
        for (int j = i + 1; j < Length;)
        {
            if (*(pArr + i) == *(pArr + j))
            {
                for (int k = j; k < Length; k++)
                {
                    *(pArr + k) = *(pArr + k + 1);
                }
                Length--;
            }
            else
            {
                j++;
            }
        }
    }
}

int main()
{
    int array[Length];

    printf("\n\nEnter an array\n");
    input(array);
    printf("\n\nArray elements: ");
    output(array);
    /*
            int n;
            printf("\n\nDelete with subscript: ");
            scanf("%d", &n);
            delBySub(array, n);
            printf("\n\nArray elements: ");
            output(array);


        int n;
        printf("\n\nDeletes elements before: ");
        scanf("%d", &n);
        delBefore(array, n);
        printf("\nArray elements: ");
        output(array);


        int n;
        printf("\n\nDeletes elements after: ");
        scanf("%d", &n);
        delAfter(array, n);
        printf("\nArray elements: ");
        output(array);

        int n;
        printf("\n\nDeletes elements: ");
        scanf("%d", &n);
        delElements(array, n);
        printf("\nArray elements: ");
        output(array);
    */

    printf("\n\nRemove duplicate elements: ");
    removeDuplicate(array);
    output(array);

    return 0;
}
