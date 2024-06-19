#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define STU 3
#define CUR 4

void my_gets(char **str, int length)
{
    *str = (char *)malloc(length * sizeof(char));
    if (fgets(*str, length, stdin))
    {
        char *find = strchr(*str, '\n');
        if (find)
        {
            *find = '\0';
        }

        if (length == (int)(strlen(*str)) + 1)
        {
            int c;
            while (EOF != (c = getchar()) && c != '\n')
            {
            }
        }
    }
}

void input(char **p_cur, char **p_id, double (*p_sco)[CUR])
{
    printf("\nEnter the course name\n\n");
    for (int i = 0; i < CUR; i++)
    {
        printf("Course %d: ", i + 1);
        my_gets(p_cur + i, 8);
    }

    printf("\nEnter the student number and score\n");
    for (int i = 0; i < STU; i++)
    {
        printf("\nStudent %d\nID: ", i + 1);
        my_gets(p_id + i, 8);
        printf("Grade\n");
        for (int j = 0; j < CUR; j++)
        {
            printf("%s: ", *(p_cur + j));
            scanf("%lf", *(p_sco + i) + j);
        }
        getchar();
    }
}

void output(char **p_cur, char **p_id, double (*p_sco)[CUR])
{
    printf("\n\nID         ");
    for (int i = 0; i < CUR; i++)
    {
        printf("%-11s", *(p_cur + i));
    }
    printf("\n");
    for (int i = 0; i < STU; i++)
    {
        printf("%-11s", *(p_id + i));
        for (int j = 0; j < CUR; j++)
        {
            printf("%-11.1f", *(*(p_sco + i) + j));
        }
        printf("\n");
    }
}

double avg_cur(double (*p_sco)[CUR])
{
    double sum = 0;
    for (int i = 0; i < STU; i++)
    {
        sum += *(*p_sco + i);
    }
    return sum / STU;
}

void avg_stu(double (*p_sco)[CUR], double *p_aver)
{
    for (int i = 0; i < STU; i++)
    {
        double sum = 0;
        for (int j = 0; j < CUR; j++)
        {
            sum += *(*(p_sco + i) + j);
        }
        *(p_aver + i) = sum / CUR;
    }
}

void findFailing(char **p_id, double (*p_sco)[CUR], const double *p_aver)
{
    for (int i = 0; i < STU; i++)
    {
        int fail = 0;
        for (int j = 0; j < CUR; j++)
        {
            if (60 > *(*(p_sco + i) + j))
            {
                fail++;
            }
        }
        if (2 <= fail)
        {
            printf("No.%s failed,scores are: ", *(p_id + i));
            for (int k = 0; k < CUR; k++)
            {
                printf("%-4.1f", *(*(p_sco + i) + k));
            }
            printf("average is %-4.1f\n", *(p_aver + i));
        }
    }
}

void findPass(char **p_id, double (*p_sco)[CUR], double *p_aver)
{
    printf("\nStudents with a grade point average of 90 or higher or a grade of 85 or higher in all classes\n");
    for (int i = 0; i < STU; i++)
    {
        int count = 0;
        for (int j = 0; j < CUR; j++)
        {
            if (85 <= *(*(p_sco + i) + j))
            {
                count++;
            }
        }

        if (90 <= *(p_aver + i) || CUR == count)
        {
            printf("%-11s\n", *(p_id + i));
        }
    }
}

int main()
{
    char *id[STU];
    char *course[CUR];
    double score[STU][CUR];
    double average[STU];

    input(course, id, score);
    output(course, id, score);
    avg_stu(score, average);

    printf("\nThe average score of the first course is %.1f\n", avg_cur(score));
    findFailing(id, score, average);
    findPass(id, score, average);

    return 0;
}
