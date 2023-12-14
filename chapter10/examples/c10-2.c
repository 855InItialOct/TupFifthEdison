#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *in, *out;

	// 定义两个字符数组，分别存放两个文件名
	char ch, infile[10], outfile[10];
	
	printf("输入读入文件的名字:");
	scanf("%s", infile);
	printf("输入输出文件的名字:");
	scanf("%s", outfile);

	// 打开输入文件
	if ((in = fopen(infile, "r")) == NULL) 
	{
		printf("无法打开此文件\n");
		exit(0);
	}

	// 打开输出文件
	if ((out = fopen(outfile, "w")) == NULL) 
	{
		printf("无法打开此文件\n");
		exit(0);
	}

	// 从输入文件读入一个字符，放在变量ch中
	ch = fgetc(in);

	// 如果未遇到输入文件的结束标志
	while (!feof(in)) 
	{
		// 将ch写到输出文件中
		fputc(ch, out);

		// 将ch显示在屏幕上
		putchar(ch);

		// 从输入文件读入一个字符，放在变量ch中
		ch = fgetc(in);
	}

	// 显示完全部字符后换行
	putchar(10);
	// 关闭输入文件
	fclose(in);
	// 关闭输出文件
	fclose(out);

	return 0;
}
