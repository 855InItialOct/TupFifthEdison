#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define N 3

struct Student
{
    int num;
    char name[20];
    double score[3];
    double aver;
};

struct Student stu[N];

void input()
{
    printf("\n输入学生信息\n");

    for (int i = 0; i < N; i++)
    {
        printf("\n学号：");
        scanf("%d%*c", &stu[i].num);
        printf("姓名：");
        scanf("%18[^\n]%*c", stu[i].name);
        printf("成绩\n");
        for (int j = 0; j < 3; j++)
        {
            printf("课程 %d：", j + 1);
            scanf("%lf", &stu[i].score[j]);
        }
    }
}

struct Student *max()
{
    for (int i = 0; i < N; i++)
    {
        double sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += stu[i].score[j];
        }
        stu[i].aver = sum / N;
    }

    int m = 0;
    for (int i = 1; i < N; i++)
    {
        if (stu[m].aver < stu[i].aver)
        {
            m = i;
        }
    }
    return stu + m;
}

void output(const struct Student *ptr)
{
    printf("\n平均成绩最高的学生\n");

    printf("学号      姓名        成绩              平均分\n");
    for (int i = 0; i < N; i++)
    {
        if (ptr->aver == stu[i].aver)
        {
            printf("%-10d%-12s", stu[i].num, stu[i].name);
            for (int j = 0; j < 3; j++)
            {
                printf("%-6.1f", stu[i].score[j]);
            }
            printf("%-5.1f\n", stu[i].aver);
        }
    }
}

int main()
{
    input();
    output(max());

    return 0;
}
