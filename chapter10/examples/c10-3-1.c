#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp;

	// str是用来存放字符串的二维数组，temp是临时数组
	char str[3][10], temp[10];
	int i, j, k, n = 3;

	printf("Enter strings:\n");
	for (i = 0; i < n; i++)
		gets(str[i]);

	// 用选择法对字符串排序
	for (i = 0; i < n - 1; i++) 
	{
		k = i;

		for (j = i + 1; j < n; j++)
			if (strcmp(str[k], str[j]) > 0)
				k = j;

		if (k != i)
		{
			strcpy(temp, str[i]);
			strcpy(str[i], str[k]);
			strcpy(str[k], temp);
		}
	}

	// 打开磁盘文件
	if ((fp = fopen("string.dat", "w")) == NULL)
	{
		printf("can't open file!\n");
		exit(0);
	}
	
	printf("\nThe new sequence:\n");
	for (i = 0; i < n; i++)
	{
		fputs(str[i], fp);

		// 撤号
		fputs("\n", fp);
		
		printf("%s\n", str[i]); 
	}
	
	return 0;
}
