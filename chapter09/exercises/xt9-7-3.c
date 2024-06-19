#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *create()
{
    Node *head = NULL;
    while (1)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (!(newNode->data))
        {
            break;
        }

        if (NULL == head)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    return head;
}

Node *delBySub(Node *head, int num)
{
    if (head)
    {
        Node *previous, *current;
        previous = current = head;
        for (int i = 1; i < num && current; i++)
        {
            previous = current;
            current = current->next;
        }
        if (NULL == current)
        {
            printf("%d is not exist in this linked list.\n", num);
            return head;
        }
        else if (head == current)
        {
            head = current->next;
        }
        else
        {
            previous->next = current->next;
        }
        free(current);
        printf("Success!\n");
    }
    return head;
}

Node *delOneElement(Node *head, int data)
{
    if (head)
    {
        Node *current, *previous;
        current = previous = head;
        while (current)
        {
            if (data == current->data)
            {
                if (head == current)
                {
                    head = current->next;
                }
                else
                {
                    previous->next = current->next;
                }
                free(current);
                printf("Success!\n");
                break;
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }
        if (NULL == current)
        {
            printf("%d is not exist in this linked list.\n", data);
        }
    }
    return head;
}

Node *delByElement(Node *head, int data)
{
    if (head)
    {
        int flag = 1;
        Node *current, *previous, *temporary;
        current = previous = head;
        while (current)
        {
            if (data == current->data)
            {
                if (head == current)
                {
                    head = current->next;
                }
                else
                {
                    previous->next = current->next;
                }
                temporary = current;
                current = current->next;
                free(temporary);
                flag = 0;
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }
        if (flag)
        {
            printf("%d is not exist in this linked list.\n", data);
        }
    }
    return head;
}

Node *delOtherDuplicate(Node *head, int data)
{
    if (head)
    {
        int flag = 1;
        Node *current, *previous, *temporary;
        for (current = head; current; current = current->next)
        {
            if (data == current->data)
            {
                if (NULL == current->next)
                {
                    printf("No duplicate elements of %d in this linked list.\n", data);
                    flag = 0;
                    break;
                }
                else
                {
                    for (previous = current->next; previous;)
                    {
                        if (data == previous->data)
                        {
                            current->next = previous->next;
                            temporary = previous;
                            previous = previous->next;
                            free(temporary);
                        }
                        else
                        {
                            previous = previous->next;
                        }
                    }
                    flag = 0;
                    printf("Success!\n");
                }
            }
        }
        if (flag)
        {
            printf("%d is not exist in this linked list.\n", data);
        }
    }

    return head;
}

Node *removeDuplicate(Node *head)
{
    if (head)
    {
        int flag = 1;
        Node *current, *temporary, *nextNode;
        for (current = head; current; current = current->next)
        {
            for (nextNode = current->next; nextNode;)
            {
                if (current->data == nextNode->data)
                {
                    current->next = nextNode->next;
                    temporary = nextNode;
                    nextNode = nextNode->next;
                    free(temporary);
                    flag = 0;
                }
                else
                {
                    nextNode = nextNode->next;
                }
            }
        }
        if (flag)
        {
            printf("No duplicate elements in this linked list.\n");
        }
        else
        {
            printf("Success!\n");
        }
    }

    return head;
}

void output(Node *head)
{
    if (head)
    {
        Node *current = head;
        while (current)
        {
            printf("%-4d", current->data);
            current = current->next;
        }
        printf("\n");
    }
    else
    {
        printf("Empty linked list.\n");
    }
}

int main()
{
    Node *head = NULL;

    printf("\nInfo\n");
    head = create();
    printf("Now\n");
    output(head);
    /*
        int n;
        printf("Delete: ");
        scanf("%d", &n);
        head = delBySub(head, n);
        printf("Now\n");
        output(head);

     */
    /*
        int n;
        printf("Delete: ");
        scanf("%d", &n);
        head = delOneElement(head, n);
        printf("Now\n");
        output(head);

      */

    /*     int n;
        printf("Delete: ");
        scanf("%d", &n);
        head = delByElement(head, n);
        printf("Now\n");
        output(head);

     */
    /*     int n;
        printf("Delete: ");
        scanf("%d", &n);
        head = delOtherDuplicate(head, n);
        printf("Now\n");
        output(head);

     */

    head = removeDuplicate(head);
    printf("Now\n");
    output(head);

    return 0;
}
