#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct node
{
	int info;
	struct node *link;
};
struct node *head;
void main()
{
	void create(),traverse(), beg();
	clrscr();
	create();
	traverse();
	beg();
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
void beg()
{
struct node * ptr,*cpt;
ptr=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter 1st info");
	scanf("%d", &ptr->info);
	cpt=head;
	while(cpt->link!=head)
	{
	cpt=cpt->link;
	}
	ptr->link=head;
	head =ptr;
	cpt->link=head;
}