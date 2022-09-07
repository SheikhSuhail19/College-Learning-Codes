#include<stdio.h>
#include<conio.h>
#define MAX 100

int q[MAX], f=-1,r=-1;


void insert()
{
	if((f == 0 && r == MAX -1) || (f == r+1))
	{
		printf("\nOverflow");
		return;
	}
	if(f == -1)
	{
		f = 0;
		r = 0;
	}
	else
		if(r == MAX-1)	
			r = 0;
		else
			++r;
	printf("\nEnter element\n");
	scanf("%d",&q[r]);
	printf("\nSuccessfully inserted\n");
}

void delete()
{
	printf("\nDeleting front element\n");
	if(f==-1)
	{
		printf("\nUnderflow");
		return;
	}
	printf("Deleted element is : %d\n",q[f]);
	if(f==r)
	{
		q[f] = '\0';
		f = -1;
		r = -1;
	}
	else
		if(f == MAX-1)
			f=0;
		else
			++f;
	printf("\nDeleted successfully\n");
}

/*
void display()
{
	int fr = f, re = r;
	if(fr == -1)
	{
		printf("Queue is Empty\n");
		return;
	}
	printf("Queue Elements are :\n");
	if(fr <= re)
		while(fr <= re)
		{
			printf("%d ",q[fr]);
			fr++;
		}
	else
	{
		while(fr <= MAX-1)
		{
			printf("%d ",q[fr]);
			fr++;
		}
	fr = 0;
	while(fr <= re)
		{
			printf("%d ",q[fr]);
			fr++;
		}
	}
	printf("\n");
}
*/

void displayi()
{
	int i;
	if(f == -1)
	{
		printf("Queue is Empty\n");
		return;
	}
	printf("Queue Elements are :\n");
	for(i = f; i != r; i = (i+1)%MAX)
		printf("%d ",q[i]);
	printf("%d ",q[r]);
	printf("\nTotal : %d",((r-f+1)%MAX));
}


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
				 displayi();
				 break;
			 case 4:
				exit(0);
			default:
				printf("Invalid Choice\n");
		}
	}
	getch();
}



