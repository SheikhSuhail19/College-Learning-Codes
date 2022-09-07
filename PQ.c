/*Implementation of Priority Queue using Linked List*/

#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<stdlib.h>

struct node
{
	int info,prn;
	struct node *link;
};
struct node *head = NULL;

void main()
{
	int ch;
	void insert(), delete(), display();
	clrscr();
	while(1)
	{
		printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter Your Choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Invalid Choice\n");
		}
	}
}

void insert()
{
	struct node *ptr,*cpt;
	ptr = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter node info with its priority:");
	scanf("%d%d",&ptr->info,&ptr->prn);
	if(head == NULL || ptr->prn < head->prn)
	{
		ptr -> link = head;
		head = ptr;
	}
	else
	{
		cpt = head;
		while(cpt ->link != NULL && cpt->link->prn <= ptr->prn)
			cpt = cpt->link;
		ptr -> link = cpt -> link;
		cpt -> link = ptr;
	}
}

void delete()
{
	struct node *ptr;
	ptr = head;
	if(ptr == NULL)
		printf("\nQueue Underflow");
	else
	{
		head = ptr -> link;
		printf("\nDeleted item is : %d with %d priority",ptr->info,ptr->prn);
		free(ptr);
	}
}

void display()
{
	struct node *ptr;
	ptr = head;
	if(ptr == NULL)
	{
		printf("\nQueue is Empty");
		return;
	}
	printf("\nPriority Queue is:\n");
	while(ptr != NULL)
	{
		printf("%d(%d)  ",ptr->info,ptr->prn);
		ptr = ptr->link;
	}
}
