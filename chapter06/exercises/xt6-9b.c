#include <stdio.h>

int main()
{
	int array[15] = {15, 14, 13, 12, 11, 10, -1, -2, -3, -4, -5, -6, -7, -8, -9};
	int mid, left = 0, right = 14;
	int num, flag = 0;

	printf("Please enter a number to looking for:");
	scanf("%d", &num);

	if (num > array[0] || num < array[14])
	{
		flag = 1;
	}
	else
	{
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (num > array[mid])
			{
				left = mid + 1;
			}
			else if (num < array[mid])
			{
				right = mid - 1;
			}
			else
			{
				printf("%d is the %dth number in the array.\n", num, mid + 1);
				break;
			}
		}
	}
	if (flag || left > right)
	{
		printf("%d is not found.\n", num);
	}

	return 0;
}