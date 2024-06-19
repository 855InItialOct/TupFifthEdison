#include <stdio.h>
#include <string.h>

#define N 1
#define CUR 3
#define IDSIZE 10
#define NAMESIZE 20

typedef struct Student
{
    char id[IDSIZE];
    char name[NAMESIZE];
    float score[CUR];
    float aver;
} Student;

void myGets(char *str, int n)
{
    fgets(str, n + 1, stdin);
    char *find = strchr(str, '\n');
    if (find)
    {
        *find = '\0';
    }
    fflush(stdin);
}

void input(Student *stu)
{
    printf("\nEnter the students' data\n");
    for (int i = 0; i < N; i++)
    {
        printf("\nID: ");
        myGets((stu + i)->id, IDSIZE);
        printf("Name: ");
        myGets((stu + i)->name, NAMESIZE);
        for (int j = 0; j < CUR; j++)
        {
            printf("Score %d: ", j + 1);
            scanf("%3f", &(stu + i)->score[j]);
            fflush(stdin);
        }
    }
}

void check(FILE *fp, char *fileName)
{
    if (NULL == (fp = fopen(fileName, "w+")))
    {
        printf("\nCan't open file.\n");
        return;
    }
}

void average(Student *stu)
{
    for (int i = 0; i < N; i++)
    {
        float sum = 0;
        for (int j = 0; j < CUR; j++)
        {
            sum += (stu + i)->score[j];
        }
        (stu + i)->aver = sum / CUR;
    }
}

void save(Student *stu, char *fileName)
{
    FILE *fp;
    check(fp, fileName);
    fputs("ID        Name               course1     course2     course3\n", fp);
    for (int i = 0; i < N; i++)
    {
        fprintf(fp, "%-10s%-20s%-12.1f%-12.1f%-12.1f\n", (stu + i)->id, (stu + i)->name, (stu + i)->score[0], (stu + i)->score[1], (stu + i)->score[2]);
    }
    fclose(fp);
}

void sort(Student *stu)
{
    for (int i = 0; i < N - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < N; j++)
        {
            if ((stu + min)->aver > (stu + j)->aver)
            {
                min = j;
            }
            if (min != i)
            {
                Student temp = stu[min];
                stu[min] = stu[i];
                stu[i] = temp;
            }
        }
    }
}

int main()
{
    Student stu[N];
    input(stu);
    average(stu);
    save(stu, "stud.txt");
    sort(stu);
    save(stu, "stud_sort.txt");

    return 0;
}
