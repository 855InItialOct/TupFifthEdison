#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
	char ID[10];
	char name[20];
	struct Student *next; 
}Student;

Student *creat()
{
	Student *head = NULL;
	Student *current = NULL;
	Student *prev = NULL;

	while(1)
	{
		current = (Student *)malloc(sizeof(Student));
		printf("ID:");
		scanf("%s", current->ID);
		printf("Name:");
		scanf("%s", current->name);
		current->next = NULL;

		if(0 == strcmp("0",current->ID))
		{
			free(current);
			break;
		}
		else
		{
			(NULL == head) ? (head = current) : (prev->next = current);
			prev = current;
		}
	}

    return head;
}

Student * connect(Student *head, Student *newNode)
{
	if(NULL != newNode)
	{
		if(head != NULL)
		{
			Student *current = head;

			while(current->next != NULL)
			{
				current = current->next;
			}
			current->next = newNode;
		}
		else
		{
			head = newNode;
		}
	}
	
	return head;
}

Student *insertionSort(Student **head)
{
	if(NULL != *head && NULL != (*head)->next)
    {
        Student *sorted = NULL;
        Student *current = *head;

        while(NULL != current)
        {
            Student *next = current->next;

            if(NULL == sorted || strcmp(current->ID,sorted->ID) < 0)
            {
                current->next = sorted;
                sorted = current;
            }
            else
            {
                Student *pos = sorted;

                while(NULL != pos->next && strcmp(current->ID,pos->next->ID) > 0)
                {
                    pos = pos->next;
                }
                current->next = pos->next;
                pos->next = current;
            }
            current = next;
        }
        *head = sorted;
    }

    return *head;
}

void print(Student *head)
{
	Student *newNode = head;

	if(NULL == head)
	{
		printf("\nList NULL!\n");
	}
	else
	{
		printf("Id                  Name\n");
		do
		{
			printf("%-20s%s\n",newNode->ID,newNode->name);
			newNode = newNode->next;
		} while (NULL != newNode);
	}
}

int main ()
{
	Student *head = NULL;
	Student *head_a = NULL;
	Student *head_b = NULL;

	printf("\nCreating Linked list A.....\n");
	head_a = creat();
	printf("\n--------List A-----------\n");
	print(head_a);

	printf("\nCreating Linked list B.....\n");
	head_b = creat();
	printf("\n--------List B-----------\n");
	print(head_b);

	printf("\nConnecting Linked list......\n");
	head = connect(head_a, head_b);
    
	printf("\n-------List A & B---------\n");
	print(head);

	printf("\n-------SortedByID---------\n");
	head = insertionSort(&head);
	print(head);

	return 0;
}