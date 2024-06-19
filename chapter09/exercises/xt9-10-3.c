#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Student
{
    long id;
    char name[20];
    float score[3];
} Student;

typedef struct _Node
{
    Student stu;
    struct _Node *next;
} Node;

Node *createLink();
void initLink(Node *);
void printLink(Node *);
void merger(Node *, Node *);
void bubbleSortByData(Node *);
void bubbleSortByNode(Node *);
void insertionSort(Node *);
void selectionSort(Node *);

int main()
{
    printf("\n\nList a\n");
    Node *head_a = createLink();
    printLink(head_a);

    printf("\n\nList b\n");
    Node *head_b = createLink();
    printLink(head_b);

    printf("\n\nMergering...\n");
    merger(head_a, head_b);
    printLink(head_a);

    printf("\nSortting...\n");
    selectionSort(head_a);
    printLink(head_a);

    return 0;
}

void myGets(char str[], int count)
{
    fgets(str, count, stdin);
    char *find = strchr(str, '\n');
    if (find)
    {
        *find = '\0';
    }
}

Node *createLink()
{
    Node *head = malloc(sizeof(Node));
    if (NULL == head)
    {
        printf("Malloc error！\n");
    }
    else
    {
        head->next = NULL;
        Node *current = head;

        printf("\nHow many students:");
        int count = 0;
        scanf("%d%*c", &count);
        for (int i = 0; i < count; i++)
        {
            Node *newNode = malloc(sizeof(Node));
            newNode->next = NULL;
            current->next = newNode;
            printf("\nID: ");
            scanf("%ld%*c", &newNode->stu.id);
            printf("Name: ");
            myGets(newNode->stu.name, 20);
            printf("\nScores\n");
            for (int j = 0; j < 3; j++)
            {
                printf("Course %d: ", j + 1);
                scanf("%f%*c", &newNode->stu.score[j]);
            }
            current = newNode;
        }
    }
    return head;
}

void printLink(Node *head)
{
    if (head)
    {
        printf("\nID          Name        course 1    course 2    course 3\n");
        for (Node *current = head->next; current; current = current->next)
        {
            printf("%-12ld%-12s", current->stu.id, current->stu.name);
            for (int i = 0; i < 3; i++)
            {
                printf("%-12.1f", current->stu.score[i]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Empty linked list.\n");
    }
}

void merger(Node *head_a, Node *head_b)
{
    Node *current = NULL;

    for (current = head_a; current->next; current = current->next)
    {
    }
    current->next = head_b->next;
}

void bubbleSortByData(Node *head)
{
    if (head)
    {
        Node *trun = NULL;
        Node *move = NULL;
        Node *save = NULL;
        for (trun = head->next; trun->next; trun = trun->next)
        {
            for (move = head->next; move->next != save; move = move->next)
            {
                if (move->stu.id > move->next->stu.id)
                {
                    Student temp = move->stu;
                    move->stu = move->next->stu;
                    move->next->stu = temp;
                }
            }
            save = move;
        }
    }
    else
    {
        printf("Empty linked list.\n");
    }
}

void bubbleSortByNode(Node *head)
{
    if (head)
    {
        Node *previous, *current, *nextNode, *tail;
        previous = current = nextNode = tail = NULL;
        for (; tail != head->next; tail = current)
        {
            for (previous = head, current = previous->next, nextNode = current->next; nextNode != tail; previous = previous->next, current = current->next, nextNode = nextNode->next)
            {
                if (current->stu.id > nextNode->stu.id)
                {
                    previous->next = nextNode;
                    current->next = nextNode->next;
                    nextNode->next = current;

                    Node *temp = nextNode;
                    nextNode = current;
                    current = temp;
                }
            }
        }
    }
    else
    {
        printf("Empty list!\n");
    }
}

void insertionSort(Node *head)
{
    Node *sorted = head;
    Node *unsorted = head->next->next;
    Node *front = head->next;

    while (unsorted)
    {
        while (sorted->next != unsorted)
        {
            if (sorted->next->stu.id > unsorted->stu.id)
            {
                Node *back = unsorted->next;
                unsorted->next = sorted->next;
                sorted->next = unsorted;
                front->next = back;
                unsorted = front;
                break;
            }
            sorted = sorted->next;
        }
        front = unsorted;
        unsorted = unsorted->next;
        sorted = head;
    }
}

void selectionSort(Node *head)
{
    if (head)
    {
        Node *sorted = NULL;
        Node *unsorted = NULL;
        Node *tag = NULL;
        Node *preTag = NULL;
        for (sorted = head; sorted->next; sorted = sorted->next)
        {
            tag = sorted->next;
            for (unsorted = sorted->next; unsorted->next; unsorted = unsorted->next)
            {
                if (tag->stu.id > unsorted->next->stu.id)
                {
                    preTag = unsorted;
                    tag = unsorted->next;
                }
            }
            if (tag != sorted->next)
            {
                preTag->next = tag->next;
                tag->next = sorted->next;
                sorted->next = tag;
            }
        }
    }
    else
    {
        printf("Empty list!\n");
    }
}