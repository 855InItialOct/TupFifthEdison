#include <stdio.h>
int main()
{
	void averScore(float *, float *);
	void averCourse_1(char(*)[10], float *);
	void fail_2(char course[5][10], int num[], float *pScore, float aver[4]);
	void good(char course[5][10], int num[4], float *pScore, float aver[4]);
	int i, j, *pNum, num[4];
	float score[4][5], aver[4], *pScore, *pAver;
	char course[5][10], (*pCourse)[10];
	printf("input course:\n");
	pCourse = course;
	for (i = 0; i < 5; i++)
		scanf("%s", course[i]);
	printf("input NO. and scores:\n");
	printf("NO.");
	for (i = 0; i < 5; i++)
		printf(",%s", course[i]);
	printf("\n");
	pScore = &score[0][0];
	pNum = &num[0];
	for (i = 0; i < 4; i++)
	{
		scanf("%d", pNum + i);
		for (j = 0; j < 5; j++)
			scanf("%f", pScore + 5 * i + j);
	}
	pAver = &aver[0];
	printf("\n\n");
	averScore(pScore, pAver);	   // 求出每个学生的平均成绩
	averCourse_1(pCourse, pScore); // 求出第一门课的平均成绩
	printf("\n\n");
	fail_2(pCourse, pNum, pScore, pAver); // 找出2门课不及格的学生
	printf("\n\n");
	good(pCourse, pNum, pScore, pAver); // 找出成绩好的学生
	return 0;
}

void averScore(float *pScore, float *pAver) // 求每个学生的平均成绩的函数
{
	int i, j;
	float sum, average;
	for (i = 0; i < 4; i++)
	{
		sum = 0.0;
		for (j = 0; j < 5; j++)
			sum = sum + (*(pScore + 5 * i + j)); // 累计每个学生的各科成绩
		average = sum / 5;						 // 计算平均成绩
		*(pAver + i) = average;
	}
}

void averCourse_1(char (*pCourse)[10], float *pScore) // 求第一课程的平均成绩的函数
{
	int i;
	float sum, average1;
	sum = 0.0;
	for (i = 0; i < 4; i++)
		sum = sum + (*(pScore + 5 * i)); // 累计每个学生的得分
	average1 = sum / 4;					 // 计算平均成绩
	printf("course 1:%s average score:%7.2f\n", *pCourse, average1);
}

void fail_2(char course[5][10], int num[], float *pScore, float aver[4])
// 找两门以上课程不及格的学生的函数
{
	int i, j, k, labe1;
	printf("        ==========Student who is fail in two courses=======  \n");
	printf("NO. ");
	for (i = 0; i < 5; i++)
		printf("%11s", course[i]);
	printf("    average\n");
	for (i = 0; i < 4; i++)
	{
		labe1 = 0;
		for (j = 0; j < 5; j++)
			if (*(pScore + 5 * i + j) < 60.0)
				labe1++;
		if (labe1 >= 2)
		{
			printf("%d", num[i]);
			for (k = 0; k < 5; k++)
				printf("%11.2f", *(pScore + 5 * i + k));
			printf("%11.2f\n", aver[i]);
		}
	}
}

void good(char course[5][10], int num[4], float *pScore, float aver[4])
// 找成绩优秀学生(各门85以上或平均90分以上)的函数
{
	int i, j, k, n;
	printf("         ======Students whose score is good======\n");
	printf("NO. ");
	for (i = 0; i < 5; i++)
		printf("%11s", course[i]);
	printf("    average\n");
	for (i = 0; i < 4; i++)
	{
		n = 0;
		for (j = 0; j < 5; j++)
			if (*(pScore + 5 * i + j) > 85.0)
				n++;
		if ((n == 5) || (aver[i] >= 90))
		{
			printf("%d", num[i]);
			for (k = 0; k < 5; k++)
				printf("%11.2f", *(pScore + 5 * i + k));
			printf("%11.2f\n", aver[i]);
		}
	}
}
