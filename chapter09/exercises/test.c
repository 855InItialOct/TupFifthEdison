#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{
    char id[8];
    int age;
    char name[20];
} Student;

typedef struct Node
{
    Student newStudent;
    struct Node *next;
} Node;

// 创建新节点
Node* createNode(Student student)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->newStudent = student;
    newNode->next = NULL;
    return newNode;
}

// 在链表末尾插入节点
void insertNode(Node** head, Student student)
{
    Node* newNode = createNode(student);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node* current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

// 删除年龄等于指定年龄的节点
void deleteNode(Node** head, int age)
{
    Node* current = *head;
    Node* previous = NULL;

    while (current != NULL)
    {
        if (current->newStudent.age == age)
        {
            if (previous == NULL)
            {
                *head = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            free(current);
            current = previous->next;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
}

// 打印链表
void printList(Node* head)
{
    Node* current = head;
    while (current != NULL)
    {
        printf("ID: %s, Age: %d, Name: %s\n", current->newStudent.id, 
        current->newStudent.age, current->newStudent.name);
        current = current->next;
    }
}

int main()
{
    Node* head = NULL;
    int age;

    // 输入链表
    for (int i = 0; i < 5; i++)
    {
        Student student;
        printf("Enter ID, Age, and Name for student %d: ", i+1);
        scanf("%s %d %s", student.id, &student.age, student.name);
        insertNode(&head, student);
    }

    // 输入要删除的年龄
    printf("Enter the age to delete: ");
    scanf("%d", &age);

    // 删除年龄等于指定年龄的节点
    deleteNode(&head, age);

    // 打印链表
    printf("Updated List:\n");
    printList(head);

    return 0;
}