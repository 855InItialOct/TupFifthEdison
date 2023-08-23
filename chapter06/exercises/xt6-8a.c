#include <stdio.h>

#define N 4
#define M 5 /* 数组为4行5列 */

int main()
{
	int i, j, k, a[N][M], max, max_j, flag;
	printf("please input matrix:\n");
	for (i = 0; i < N; i++) /* 输入数组 */
		for (j = 0; j < M; j++)
			scanf("%d", &a[i][j]);
	for (i = 0; i < N; i++)
	{
		max = a[i][0];			/* 开始时假设a[i][0]最大 */
		max_j = 0;				/* 将列号0赋给max_j保存 */
		for (j = 0; j < M; j++) /* 找出第i行中的最大数 */
			if (a[i][j] > max)
			{
				max = a[i][j]; /* 将本行的最大数存放在max中 */
				max_j = j;	   /* 将最大数所在的列号存放在max_j中 */
			}
		flag = 1; /* 先假设是鞍点，以flag为1代表 */
		for (k = 0; k < N; k++)
			if (max > a[k][max_j]) /* 将最大数和其同列元素相比 */
			{
				flag = 0; /* 如果max不是同列最小，表示不是鞍点令flag1为0 */
				continue;
			}
		if (flag) /* 如果flag1为1表示是鞍点 */
		{
			printf("a[%d][%d]=%d\n", i, max_j, max); /* 输出鞍点的值和所在行列号 */
			break;
		}
	}
	if (!flag) /* 如果flag为0表示鞍点不存在 */
		printf("It is not exist!\n");
	return 0;
}
