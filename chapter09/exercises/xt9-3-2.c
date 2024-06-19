#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define STU 5
#define CUR 3

typedef struct gradeTable
{
    char num[7];
    char name[20];
    float score[CUR];
} GradeTable;

void print(GradeTable table[])
{
    printf("\n\n学号\t姓名\t\t\t  成绩\n");
    for (int i = 0; i < STU; i++)
    {
        printf("%-8s%-20s", table[i].num, table[i].name);
        for (int j = 0; j < CUR; j++)
        {
            printf("%-6.1f", table[i].score[j]);
        }
        printf("\n");
    }
}

int main()
{
    GradeTable student[STU];

    printf("\n输入学生信息\n");
    for (int i = 0; i < STU; i++)
    {
        printf("\n学号：");
        scanf("%6[^\n]%*c", student[i].num);

        printf("姓名：");
        scanf("%18[^\n]%*c", student[i].name);

        printf("\n成绩\n\n");
        for (int j = 0; j < CUR; j++)
        {
            printf("课程 %d: ", j + 1);
            scanf("%f%*c", &student[i].score[j]);
        }
    }

    print(student);

    return 0;
}
