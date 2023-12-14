#include <stdlib.h>
#include <stdio.h>
int main()
{
	FILE *fp;
	char ch, filename[10];

	printf("请输入所用的文件名：");
	scanf("%s", filename);

	// 打开输出文件并使fp指向此文件
	if ((fp = fopen(filename, "w")) == NULL) 
	{
		// 如果打开时出错，就输出"打不开"的信息
		printf("无法打开此文件\n"); 

		// 终止程序
		exit(0);
	}

	// 接收在执行scanf语句时最后输入的回车符
	ch = getchar(); 

	printf("请输入一个准备存储到磁盘的字符串(以#结束)：");

	// 接收从键盘输入的第一个字符
	ch = getchar();

	// 当输入'#'时结束循环
	while (ch != '#') 
	{
		// 向磁盘文件输出一个字符
		fputc(ch, fp);

		// 将输出的字符显示在屏幕上
		putchar(ch);

		// 再接收从键盘输入的一个字符
		ch = getchar();
	}

	// 关闭文件
	fclose(fp);
	
	// 向屏幕输出一个换行符，换行符的ASCII代码为10
	putchar(10);

	return 0;
}
