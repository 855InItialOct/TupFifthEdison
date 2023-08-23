#include <stdio.h>
#define N 15
int main()
{
	int i, number, top, bott, mid, local, a[N], flag = 1, sign;
	char c;
	printf("enter data:\n");
	scanf("%d", &a[0]);
	i = 1;
	while (i < N)
	{
		scanf("%d", &a[i]);
		if (a[i] >= a[i - 1])
			i++;
		else
			printf("enter this data again:\n");
	}
	printf("\n");
	for (i = 0; i < N; i++)
		printf("%5d", a[i]);
	printf("\n");
	while (flag)
	{
		printf("input number to look for:");
		scanf("%d", &number);
		sign = 0;
		top = 0;									// top是查找区间的起始位置
		bott = N - 1;								// bott是查找区间的最末位置
		if ((number < a[0]) || (number > a[N - 1])) // 要查的数不在查找区间内
			local = -1;								// 表示找不到
		while ((!sign) && (top <= bott))
		{
			mid = (bott + top) / 2;
			if (number == a[mid])
			{
				local = mid;
				printf("Has found %d, its position is %d\n", number, local + 1);
				sign = 1;
			}
			else if (number < a[mid])
				bott = mid - 1;
			else
				top = mid + 1;
		}
		if (!sign || local == -1)
			printf("cannot find %d.\n", number);
		;
		printf("continue or not(Y/N)?");
		scanf(" %c", &c);
		if (c == 'N' || c == 'n')
			flag = 0;
	}
	return 0;
}
