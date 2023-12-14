#include <stdio.h>
int main()
{
	FILE *fp1, *fp2;
	fp1 = fopen("file1.dat", "r"); 
	fp2 = fopen("file2.dat", "w"); 

	// 逐个读入字符并输出到屏幕
	while (!feof(fp1))
		putchar(getc(fp1)); 
	putchar(10);

	// 使文件位置指示器返回文件头
	rewind(fp1);

	// 从文件头重新逐个读字符，输出到file2文件
	while (!feof(fp1))
		putc(getc(fp1), fp2);

	fclose(fp1);
	fclose(fp2);
	
	return 0;
}
