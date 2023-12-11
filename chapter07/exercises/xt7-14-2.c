#include <stdio.h>
#include <math.h>

#define STUDENT 5
#define COURSE 4

void input(char *name[], char *course[],float array[][COURSE])
{
    printf("Please enter the student's grades.\n");
    for (int i = 0; i < STUDENT - 1; i++)
    {
        printf("\n%s\n", name[i]);
        for (int j = 0; j < COURSE - 1; j++)
        {
            printf("%s: ", course[j]);
            scanf("%f", &array[i][j]);
        }
    }
}

void output(char *name[], char *course[],float array[][COURSE])
{
    printf("\t\t");
    for (int i = 0; i < COURSE; i++)
    {
        printf("%12s", course[i]);
    }
    printf("\n");
    for (int i = 0; i < STUDENT; i++)
    {
        printf("%12s\t", name[i]);
        for (int j = 0; j < COURSE; j++)
        {
            printf("%12.1f", array[i][j]);
        }
        printf("\n");
    }
}

void highest(float array[][COURSE])
{
    float max = array[0][0];
    int row, column;
    for (int i = 0; i < COURSE; i++)
    {
        for (int j = 0; j < COURSE; j++)
        {
            if (array[i][j] > max)
            {
                max = array[i][j];
                row = i;
                column = j;
            }
        }
    }
    printf("\nThe highest grade is %.1f at %d,%d\n", max, row + 1, column + 1);
}

void stuAvg(float array[][COURSE])
{
    int i, j;
    float sum;
    for (i = 0; i < STUDENT - 1; i++)
    {
        for ( j = 0, sum = 0; j < COURSE-1; j++)
        {
            sum += array[i][j];
        }
        array[i][j] = sum/(COURSE-1);
    }
}

void couAvg(float array[][COURSE])
{
    int i, j;
    float sum = 0;
    for (i = 0; i < COURSE - 1; i++)
    {
        for (j = 0, sum = 0; j < STUDENT - 1; j++)
        {
            sum += array[j][i];
        }
        array[j][i] = sum / (STUDENT - 1);
    }
}

void sigma(float array[][COURSE])
{
    float variance, sum1 = 0, sum2 = 0;
    for (int i = 0; i < STUDENT - 1;i++)
    {
        sum1 += pow(array[i][COURSE - 1],2);
        sum2 += array[i][COURSE - 1];
    }
    variance = sum1 / (STUDENT - 1) - pow(sum2 / (STUDENT + 1), 2);
    printf("The mean score variance was %.1f\n", variance);
}

int main()
{
    float grade[STUDENT][COURSE] = {0};
    char *name[] = {"Lily", "Ethan", "Ava", "Noah","average"};
    char *course[] = {"Chinese", "Math", "English","average"};

    input(name, course, grade);
    stuAvg(grade);
    couAvg(grade);
    output(name, course, grade);
    highest(grade);
    sigma(grade);

    return 0;   
}