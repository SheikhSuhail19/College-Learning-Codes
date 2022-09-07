#include<stdio.h>
#include<conio.h>
#define MAX 5
int q[MAX], f=-1,r=-1;

void create()
{
	char ch;
	f=0;
	do{
		r++;
		printf("\nEnter element\n");
		scanf("%d",&q[r]);
		printf("Y or N\n");
		ch=getch();
	}
	while(ch == 'y');
}

void traverse()
{
	int i;
	printf("\nTraversing list :\n");
	for(i=f;i<=r;i++)
		printf("%d\n",q[i]);
	printf("%d\n",(r-f+1));
}

void insert()
{
	int m;
	printf("Inserting element");
	if(r == MAX -1)
	{
		printf("\nOverflow");
		return;
	}
	printf("\nEnter element\n");
	scanf("%d",&m);
	r++;
	q[r] = m;
	printf("Successfull");
}

void delete()
{
	printf("Deleting front element");
	if(f==-1)
	{
		printf("\nUnderflow");
		return;
	}
	if(f==r)
	{
		printf("%d\n",q[f]);
		q[f] = '\0';
		f = -1;
		r = -1;
	}
	else
	{
		printf("%d\n",q[f]);
		q[f] = '\0';
		f++;
	}
	printf("Deleted successfully");
}

void main()
{
	clrscr();
	create();
	traverse();
	insert();
	traverse();
	delete();
	traverse();
	getch();
}