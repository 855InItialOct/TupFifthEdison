#include <stdio.h>
#include <string.h>

void selectionSort(char (*ptr)[20], int n)
{
	char temp[20], *p = temp;
	for (int i = 0; i < n - 1; i++)
	{
		char *min = *(ptr + i);
		for (int j = i + 1; j < n; j++)
		{
			if (0 < strcmp(min, *(ptr + j)))
			{
				min = *(ptr + j);
			}
		}
		if (min != *(ptr + i))
		{
			strcpy_s(p, 20, *(ptr + i));
			strcpy_s(*(ptr + i), 20, min);
			strcpy_s(min, 20, p);
		}
	}
}

int main()
{
	char str[5][20];
	for (int i = 0; i < 5; i++)
	{
		if (fgets(str[i], 20, stdin))
		{
			char *find = strchr(str[i], '\n');
			if (find)
			{
				*find = '\0';
			}
		}
	}

	selectionSort(str, 5);

	for (int i = 0; i < 5; i++)
	{
		puts(str[i]);
	}

	return 0;
}