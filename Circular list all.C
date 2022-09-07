#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct node
{
	int info;
	struct node *link;
};
struct node *head,*head2;
void main()
{
	void create(),create2(),traverse(),traverse2(), concate();
	clrscr();
	create();
	traverse();
	create2();
	traverse2();
	concate();
	traverse();
	getch();
}
void create()
{
	struct node * ptr, *cpt;
	char ch;
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter 1st info");
	scanf("%d", &ptr->info);
	head=ptr;
	do
	{
		cpt=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter next node info");
		scanf("%d",&cpt->info);
		ptr->link=cpt;
		ptr=cpt;
		printf("Enter Y/N for more node");
		ch=getch();
	}
	while(ch == 'y');
	ptr->link=head;
}
void traverse()
{
	struct node *ptr;
	printf("\nTraversing list");
	ptr=head;
	while(ptr->link!=head)
	{
	printf("%d", ptr->info);
	ptr=ptr->link;
	}
	printf("%d",ptr->info);
}

void traverse2()
{
	struct node *ptr;
	printf("\nTraversing list");
	ptr=head2;
	while(ptr->link!=head2)
	{
	printf("%d", ptr->info);
	ptr=ptr->link;
	}
	printf("%d",ptr->info);
}

void create2()
{
	struct node * ptr, *cpt;
	char ch;
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter 1st info");
	scanf("%d", &ptr->info);
	head2=ptr;
	do
	{
		cpt=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter next node info");
		scanf("%d",&cpt->info);
		ptr->link=cpt;
		ptr=cpt;
		printf("Enter Y/N for more node");
		ch=getch();
	}
	while(ch == 'y');
	ptr->link=head2;
}

void concate()
{
	struct node *ptr,*cpt;
	ptr=head;
	while(ptr->link!=head)
	{
	ptr=ptr->link;
	}
	ptr->link=head2;
	cpt=head2;
	while(cpt->link!=head2)
	{
	cpt=cpt->link;
	}
	cpt->link=head;
}
