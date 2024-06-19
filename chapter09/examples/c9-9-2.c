#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <stdio.h>

#define LEN sizeof(Student)

typedef struct Student
{
    long num;
    float score;
    struct Student *next;
} Student;

int n;

Student *create()
{
    Student *current, *previous;
    current = previous = (Student *)malloc(LEN);
    scanf("%ld%f", &current->num, &current->score);

    Student *head = NULL;
    n = 0;
    while (current->num)
    {
        n++;
        if (1 == n)
        {
            head = current;
        }
        else
        {
            previous->next = current;
        }
        previous = current;
        current = (struct Student *)malloc(sizeof(struct Student));
        scanf("%ld%f", &current->num, &current->score);
    }
    previous->next = NULL;

    return head;
}

void output(Student *head)
{
    if (head)
    {
        Student *p = head;
        printf("\n学号      成绩\n");
        while (p)
        {
            printf("%-10ld%-10.1f\n", p->num, p->score);
            p = p->next;
        }
    }
}

int main()
{
    output(create());

    return 0;
}
