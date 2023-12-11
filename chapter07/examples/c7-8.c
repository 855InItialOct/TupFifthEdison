#include <stdio.h>

int main()
{
	// 对hanoi函数的声明
	void hanoi(int n, char one, char two, char three); 

	int m;

	printf("input the number of disks:");
	scanf("%d", &m);

	printf("The step to move %d disks:\n", m);
	hanoi(m, 'A', 'B', 'C');

	return 0;
}

// 定义hanoi函数
// 将n个盘从one座借助two座,移到three座
void hanoi(int n, char one, char two, char three) 
{
	// 对move函数的声明
	void move(char x, char y); 

	if (n == 1)
		move(one, three);
	else
	{
		hanoi(n - 1, one, three, two);
		move(one, three);
		hanoi(n - 1, two, one, three);
	}
}

// 定义move函数
void move(char x, char y) 
{
	printf("%c-->%c\n", x, y);
}
