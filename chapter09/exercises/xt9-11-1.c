#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN sizeof(Node)
#define NAMESIZE 20

typedef struct _Student
{
    int id;
    char name[NAMESIZE];
    float score;
} Student;

typedef struct _Node
{
    Student stu;
    struct _Node *next;
} Node;

void delete_menu()
{
    printf("\n=======================================\n");
    printf("==1.Deleting specified student data====\n");
    printf("==2.Deleting duplicate student data====\n");
    printf("==3.Deleting the same student numbers==\n");
    printf("=======================================\n");
}

Node *deleteSpecified(Node *head, int data)
{
    if (head)
    {
        int flag = 0;
        Node *previous = head;
        Node *current = head;
        while (current)
        {
            if (data == current->stu.id)
            {
                flag = 1;
                if (head == current)
                {
                    head = current->next;
                }
                else
                {
                    previous->next = current->next;
                }
                Node *temporary = current;
                current = current->next;
                free(temporary);
                temporary = NULL;
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }
        if (flag)
        {
            printf("SUCCESS!\n");
        }
        else
        {
            printf("%d NOT EXIST!\n", data);
        }
    }
    else
    {
        printf("EMPTY LIST!\n");
    }

    return head;
}

Node *deleteDuplicate(Node *head)
{
    if (head)
    {
        int flag = 0;
        for (Node *trun = head; trun; trun = trun->next)
        {
            for (Node *current = trun; current->next; current = current->next)
            {
                if (trun->stu.id == current->next->stu.id)
                {
                    flag = 1;
                    Node *temporary = current->next;
                    current->next = current->next->next;
                    free(temporary);
                    temporary = NULL;
                }
            }
        }
        if (flag)
        {
            printf("SUCCESS!\n");
        }
        else
        {
            printf("NO DUPLICATES\n");
        }
    }
    else
    {
        printf("EMPTY LIST!\n");
    }
    return head;
}

Node *deleteTheSame(Node *a_head, Node *b_head)
{
    if (a_head && b_head)
    {
        int flag = 1;
        for (Node *trun = b_head; trun; trun = trun->next)
        {
            if (trun->stu.id == a_head->stu.id)
            {
                flag = 0;
                a_head = a_head->next;
            }
            else
            {
                Node *previous = a_head;
                Node *move = a_head->next;
                while (move)
                {
                    if (move->stu.id == trun->stu.id)
                    {
                        flag = 0;
                        previous->next = move->next;
                    }
                    previous = move;
                    move = move->next;
                }
            }
        }
        if (flag)
        {
            printf("NOT EXIST THE SAME ELEMENTS!");
        }
    }

    return a_head;
}

Node *delete_link_list(Node *head)
{
    if (head)
    {

        int option = 0;
        int id = 0;
        int age = 0;
        char ch;
        Node *head_2 = NULL;

        while (1)
        {
            delete_menu();
            printf("\nChoose(1/2/3): ");
            scanf("%d%*c", &option);

            switch (option)
            {
            case 1:
                printf("\nID: ");
                scanf("%d%*c", &id);
                head = deleteSpecified(head, id);
                break;
            case 2:
                head = deleteDuplicate(head);
                break;
            case 3:
                head_2 = create_link_list();
                output_link_list(head_2);
                printf("Delete from the a list the element with the same student number as in the b list\n");
                break;
            default:
                printf("\nINPUT ERROR!\n");
                break;
            }
            output_link_list(head);
            printf("\nContinue or not?(Y/N): ");
            scanf("%c%*c", &ch);
            if ('n' == ch || 'N' == ch)
            {
                printf("EXIT!\n");
                break;
            }
            else if (NULL == head)
            {
                printf("EMPTY LIST!\n");
                break;
            }
        }
    }
    else
    {
        printf("\nEMPTY LIST!\n");
    }

    return head;
}

void my_gets(char *buf)
{
    fgets(buf, NAMESIZE, stdin);
    char *find = strchr(buf, '\n');
    if (find)
    {
        *find = '\0';
    }
}

Node *create_link_list()
{
    Node *head = NULL;
    Node *current = NULL;

    while (1)
    {
        Node *newNode = malloc(LEN);
        if (NULL == newNode)
        {
            printf("\nMALLOC ERROR!\n");
            break;
        }
        else
        {
            printf("\nID:");
            scanf("%d%*c", &newNode->stu.id);
            if (0 == newNode->stu.id)
            {
                free(newNode);
                printf("DONE!\n");
                break;
            }
            printf("Name:");
            my_gets(newNode->stu.name);
            printf("Score:");
            scanf("%f%*c", &newNode->stu.score);
            newNode->next = NULL;
            if (NULL == head)
            {
                head = newNode;
                current = head;
            }
            else
            {
                current->next = newNode;
                current = current->next;
            }
        }
    }

    return head;
}

void output_link_list(Node *head)
{
    if (head)
    {
        printf("\nID      NAME        SCORE\n");
        for (Node *current = head; current; current = current->next)
        {
            printf("%-8d%-12s%-8.1f\n", current->stu.id, current->stu.name, current->stu.score);
        }
    }
    else
    {
        printf("\nEMPTY LIST!\n");
    }
}

int main()
{

    printf("\nEnter the student data(0 for end)\n");

    Node *head = NULL;

    head = create_link_list();
    output_link_list(head);
    head = delete_link_list(head);

    return 0;
}
