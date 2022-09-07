#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};
struct node *f = NULL, *r = NULL;

void main()
{
	int ch;
	void insert(),delete(),display();
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
			default:
				printf("Invalid Choice\n");
		}
	}
	getch();
}

void insert()
{
	struct node *ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	printf("Enter item to insert");
	scanf("%d",&ptr->info);
	ptr->link = ptr;
	if(f==NULL)
	{
		f = ptr;
		r = ptr;
	}
	else
	{
		r->link = ptr;
		r = ptr;
	}
	r->link = f;
}

void delete()
{
	struct node *ptr;
	if(f == NULL)
	{
		printf("\nQueue Underflow");
		return;
	}
	if(f == r)
	{
		free(f);
		f = NULL;
		r = NULL;
	}
	else
	{
		ptr = f;
		f = ptr->link;
		r -> link = f;
		free(ptr);
	}
}

void display()
{
	struct node *ptr;
	ptr = f;
	if(ptr == NULL)
		printf("\nQueue Empty");
	else
	{
		printf("\nElements in Queue are :\n");
		while(ptr-> link != f)
		{
			printf("%d ",ptr->info);
			ptr = ptr->link;
		}
		printf("%d\n",ptr->info);
	}
}