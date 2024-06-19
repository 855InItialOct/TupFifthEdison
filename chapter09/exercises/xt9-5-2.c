#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define STU 2
#define CUR 3

typedef struct
{
    char id[8];
    char name[20];
    float score[CUR];
    float aver;
} StuData;

void input(StuData student[])
{
    printf("\n\n输入学生信息\n");
    for (int i = 0; i < STU; i++)
    {
        printf("\n学号: ");
        scanf("%7[^\n]%*c", student[i].id);
        printf("姓名: ");
        scanf("%18[^\n]%*c", student[i].name);
        printf("\n成绩\n\n");
        for (int j = 0; j < CUR; j++)
        {
            printf("课程 %d: ", j + 1);
            scanf("%f%*c", &student[i].score[j]);
        }
    }
}

void print(StuData student[])
{
    printf("\n\n学号    姓名              成绩\n");
    for (int i = 0; i < STU; i++)
    {
        printf("%-8s%-12s", student[i].id, student[i].name);
        for (int j = 0; j < CUR; j++)
        {
            printf("%-6.1f", student[i].score[j]);
        }
        printf("\n");
    }
}

float avg_c(StuData student[])
{
    float total = 0;
    for (int i = 0; i < STU; i++)
    {
        float sum = 0;
        for (int j = 0; j < CUR; j++)
        {
            sum += student[i].score[j];
        }
        student[i].aver = sum / CUR;
        total += student[i].aver;
    }
    return total / STU;
}

StuData *findHighest(StuData stuData[])
{
    StuData *highest = stuData;

    for (int i = 1; i < STU; i++)
    {
        for (int j = 0; j < CUR; j++)
        {
            if (highest->aver < stuData[i].aver)
            {
                highest = stuData + i;
            }
        }
    }
    return highest;
}

int main()
{
    StuData student[STU];
    input(student);
    print(student);
    printf("\n\n课程总平均分：%-6.1f\n", avg_c(student));
    printf("\n\n总分最高的学生\n");
    printf("\n学号    姓名              成绩        平均分\n");
    const StuData *highest = findHighest(student);
    for (int i = 0; i < STU; i++)
    {
        if (highest->aver == student[i].aver)
        {
            printf("%-8s%-12s", student[i].id, student[i].name);
            for (int j = 0; j < CUR; j++)
            {
                printf("%-6.1f", student[i].score[j]);
            }
            printf("%-6.1f\n", student[i].aver);
        }
    }

    return 0;
}