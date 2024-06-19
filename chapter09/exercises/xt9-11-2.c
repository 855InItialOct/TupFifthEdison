#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IDSIZE 2
#define NAMESIZE 3

typedef struct _Student
{
    char id[IDSIZE];
    char name[NAMESIZE];
} Student;

typedef struct _Node
{
    Student stu;
    struct _Node *next;
} Node;

Node *crtLinkList();
void prtLinkList(Node *);
Node *del(Node *, Node *);

int main()
{
    printf("\n\nList a\n");
    Node *head_a = crtLinkList();
    prtLinkList(head_a);

    printf("\n\nList b\n");
    Node *head_b = crtLinkList();
    prtLinkList(head_b);

    printf("\nDeleting...\n");
    Node *head = del(head_a, head_b);
    prtLinkList(head);

    return 0;
}

void myGets(char *str, int size)
{
    fgets(str, size, stdin);

    char *find = strchr(str, '\n');
    if (find)
    {
        *find = '\0';
    }

    fflush(stdin);
}

Node *crtLinkList()
{
    Node *head = NULL;
    Node *current = NULL;

    while (1)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->next = NULL;

        printf("\nID: ");
        myGets(newNode->stu.id, IDSIZE);

        if (!strcmp(newNode->stu.id, "0"))
        {
            printf("\nDONE");
            break;
        }

        printf("Name: ");
        myGets(newNode->stu.name, NAMESIZE);

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
    return head;
}

void prtLinkList(Node *head)
{
    printf("\nID          Name\n");
    for (Node *current = head; current; current = current->next)
    {
        printf("%-12s%-12s\n", current->stu.id, current->stu.name);
    }
}

Node *del(Node *desc, Node *src)
{
    Node *check = NULL;
    Node *current = NULL;
    Node *previous = NULL;
    Node *head = desc;
    for (check = src; check; check = check->next)
    {
        for (current = head, previous = desc; current;)
        {
            if (!strcmp(current->stu.id, check->stu.id))
            {
                if (head == current)
                {
                    head = current->next;
                }
                else
                {
                    previous->next = current->next;
                }
                previous = current->next;
                free(current);
                current = previous;
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }
    }

    return head;
}