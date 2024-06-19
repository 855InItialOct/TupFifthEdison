#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1

typedef struct Employee
{
    char name[20];
    char title[10];
    char sex;
    int age;
    char addr[32];
    float sal;
    char status[10];
    char edu[20];
} Emp;

typedef struct EmployeeSalary
{
    char title[20];
    float sal;
} Emp_s;

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

void input(char *fileName)
{
    Emp emp[N];
    printf("\nEnter the data of employees\n");
    for (int i = 0; i < N; i++)
    {
        printf("\nemployee %d\n", i + 1);
        printf("Name: ");
        myGets((emp + i)->name, 20);
        printf("ID: ");
        myGets((emp + i)->title, 10);
        printf("Sex: ");
        scanf("%c", &(emp + i)->sex);
        fflush(stdin);
        printf("Age: ");
        scanf("%2d", &(emp + i)->age);
        fflush(stdin);
        printf("Address: ");
        myGets((emp + i)->addr, 32);
        printf("Salary: ");
        scanf("%6f", &(emp + i)->sal);
        fflush(stdin);
        printf("Health status: ");
        myGets((emp + i)->status, 10);
        printf("Degree of education: ");
        myGets((emp + i)->edu, 20);
    }
    FILE *fp;
    if (NULL == (fp = fopen(fileName, "wb+")))
    {
        printf("\nCan't open file %s.\n", fileName);
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (1 != fwrite((emp + i), sizeof(Emp), 1, fp))
        {
            printf("\nFile write error.\n");
        }
        else
        {
            printf("%-12s%-12s%-12c%-12d%-12s%-12.1f%-12s%-12s\n",
                   (emp + i)->name, (emp + i)->title, (emp + i)->sex,
                   (emp + i)->age, (emp + i)->addr, (emp + i)->sal,
                   (emp + i)->status, (emp + i)->edu);
        }
    }
    fclose(fp);
}

void simplify(char *fileName1, char *fileName2)
{
    FILE *fp1, *fp2;

    if (NULL == (fp1 = fopen(fileName1, "rb+")))
    {
        printf("\nCan't open file %s.\n", fileName1);
        return;
    }
    if (NULL == (fp2 = fopen(fileName2, "wb+")))
    {
        printf("\nCan't open file %s.\n", fileName2);
        return;
    }

    Emp emp[N];
    Emp_s sal[N];

    for (int i = 0; i < N; i++)
    {
        if (1 != fread((emp + i), sizeof(Emp), 1, fp1))
        {
            if (feof(fp1))
            {
                fclose(fp1);
                return;
            }
            printf("\nFile %s read error.\n", fileName1);
        }
        else
        {
            printf("%-12s%-12s%-12c%-12d%-12s%-12.1f%-12s%-12s\n",
                   (emp + i)->name, (emp + i)->title, (emp + i)->sex,
                   (emp + i)->age, (emp + i)->addr, (emp + i)->sal,
                   (emp + i)->status, (emp + i)->edu);
            strcpy((sal + i)->title, ((emp + i)->title));
            (sal + i)->sal = (emp + i)->sal;
            if (1 != fwrite((sal + i), sizeof(Emp_s), 1, fp2))
            {
                if (feof(fp2))
                {
                    fclose(fp2);
                    return;
                }
                printf("\nFile %s read error.\n", fileName2);
            }
            else
            {
                printf("%-12s%-12.1f\n",
                       (sal + i)->title, (sal + i)->sal);
            }
        }
    }
    fclose(fp2);
    fclose(fp1);
}

int main()
{
    char fileName1[20], fileName2[20];

    printf("\nFile name 1: ");
    myGets(fileName1, 15);
    strcat(fileName1, ".dat");
    input(fileName1);

    printf("\nFile name 2: ");
    myGets(fileName2, 15);
    strcat(fileName2, ".dat");
    simplify(fileName1, fileName2);

    return 0;
}
