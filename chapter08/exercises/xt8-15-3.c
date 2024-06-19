#include <stdio.h>

#define NUM_STUDENTS 4
#define NUM_COURSES 5

struct Student
{
    int id;
    int scores[NUM_COURSES];
    float average;
};

void calculateAverage(struct Student *student)
{
    float sum = 0;
    for (int i = 0; i < NUM_COURSES; i++)
    {
        sum += student->scores[i];
    }
    student->average = sum / NUM_COURSES;
}

void printStudent(struct Student student)
{
    printf("学号：%d\n", student.id);
    printf("成绩：");
    for (int i = 0; i < NUM_COURSES; i++)
    {
        printf("%d ", student.scores[i]);
    }
    printf("\n");
    printf("平均成绩：%.2f\n", student.average);
    printf("\n");
}

int main()
{
    struct Student students[NUM_STUDENTS] = {
        {1, {80, 85, 90, 95, 100}, 0},
        {2, {70, 75, 80, 85, 90}, 0},
        {3, {60, 65, 70, 75, 80}, 0},
        {4, {90, 95, 100, 85, 90}, 0}};

    // 求第一门课程的平均分
    float firstCourseAverage = 0;
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        firstCourseAverage += students[i].scores[0];
    }
    firstCourseAverage /= NUM_STUDENTS;
    printf("第一门课程的平均分：%.2f\n\n", firstCourseAverage);

    // 求学生的平均分
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        calculateAverage(students + i);
    }

    // 找出有两门以上课程不及格的学生
    printf("有两门以上课程不及格的学生：\n");
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        int numFailures = 0;
        for (int j = 0; j < NUM_COURSES; j++)
        {
            if (students[i].scores[j] < 60)
            {
                numFailures++;
            }
        }
        if (numFailures >= 2)
        {
            printStudent(students[i]);
        }
    }

    // 找出平均成绩在90分以上或全部课程成绩在85分以上的学生
    printf("平均成绩在90分以上或全部课程成绩在85分以上的学生：\n");
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        if (students[i].average >= 90)
        {
            printStudent(students[i]);
        }
        else
        {
            int allAbove85 = 1;
            for (int j = 0; j < NUM_COURSES; j++)
            {
                if (students[i].scores[j] < 85)
                {
                    allAbove85 = 0;
                    break;
                }
            }
            if (allAbove85)
            {
                printStudent(students[i]);
            }
        }
    }

    return 0;
}