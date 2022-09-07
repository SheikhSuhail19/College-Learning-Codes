/*Implementation of Dequeue using Linked List*/

#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *fptr,*bptr;
};
struct node *f = NULL, *r = NULL;

void main()
{
	int ch;
	void insert_f(),insert_r(),delete_f(),delete_r(),display();
	clrscr();
	while(1)
	{
		printf("\n1. Insert at Front\n2. Insert at Rear\n3. Delete at Front");
		printf("\n4. Delete at Rear\n5. Display\n6. Exit\nEnter Your Choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert_f();
				break;
			case 2:
				insert_r();
				break;
			case 3:
				delete_f();
				break;
			case 4:
				delete_r();
				break;
			case 5:
				 display();
				 break;
			 case 6:
				exit(0);
			default:
				printf("Invalid Choice\n");
		}
	}
}

void insert_f()
{
	struct node *ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	printf("Enter item to insert");
	scanf("%d",&ptr->info);
	ptr->fptr = NULL;
	ptr->bptr = NULL;
	if(f==NULL)
	{
		f = ptr;
		r = ptr;
	}
	else
	{
		f->bptr = ptr;
		ptr->fptr = f;
		f = ptr;
	}
}

void insert_r()
{
	struct node *ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	printf("Enter item to insert");
	scanf("%d",&ptr->info);
	ptr->fptr = NULL;
	ptr->bptr = NULL;
	if(f==NULL)
	{
		f = ptr;
		r = ptr;
	}
	else
	{
		r->fptr = ptr;
		ptr->bptr = r;
		r = ptr;
	}
}

void delete_f()
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
		f = ptr->fptr;
		free(ptr);
	}
	f->bptr = NULL;
}

void delete_r()
{
	struct node *ptr;
	if(f == NULL)
	{
		printf("\nQueue Underflow");
		return;
	}
	if(f == r)
	{
		free(r);
		f = NULL;
		r = NULL;
	}
	else
	{
		ptr = r;
		r = ptr->bptr;
		free(ptr);
	}
	r->fptr = NULL;
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
		while(ptr->fptr != NULL)
		{
			printf("%d ",ptr->info);
			ptr = ptr->fptr;
		}
		printf("%d\n",ptr->info);
	}
}
