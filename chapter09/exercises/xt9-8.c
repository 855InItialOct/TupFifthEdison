#include <stdio.h>
struct student
{
	long num;
	float score;
	struct student *next;
};
int n;

struct student *insert(struct student *head, struct student *stud)
{
	struct student *p0, *p1, *p2;
	p1 = head;		  // 使ｐ１指向第一个结点
	p0 = stud;		  // 指向要插入的结点
	if (head == NULL) // 原来的链表是空表
	{
		head = p0;
		p0->next = NULL;
	} // 使ｐ０指向的结点作为头结点
	else
	{
		while ((p0->num > p1->num) && (p1->next != NULL))
		{
			p2 = p1; // 使ｐ２指向刚才p１指向的结点
			p1 = p1->next;
		} // p1后移一个结点
		if (p0->num <= p1->num)
		{
			if (head == p1)
				head = p0; // 插到原来第一个结点之前
			else
				p2->next = p0; // 插到p2指向的结点之后
			p0->next = p1;
		}
		else
		{
			p1->next = p0;
			p0->next = NULL; // 插到最后的结点之后
		}
	}
	n = n + 1; // 结点数加１
	return (head);
}
