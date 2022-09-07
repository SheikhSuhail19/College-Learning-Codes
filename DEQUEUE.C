/*Implementation of Dequeue using Array*/

#include<stdio.h>
#include<conio.h>
#define MAX 100

int q[MAX], f=-1,r=-1;

void main()
{
	int ch;
	void insert_f(),insert_r(),delete_f(),delete_r(),display();
	clrscr();
	while(1)
	{
		printf("\n1. Insert at Front\n2. Insert at Rear\n3. Delete at Front\n");
		printf("4. Delete at Rear\n5. Display\n6. Exit\nEnter Your Choice\n");
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
	if((f == 0 && r == MAX -1) || (f == r+1))
	{
		printf("\nDeque is Overflow");
		return;
	}
	if(f == -1)
	{
		f = 0;
		r = 0;
	}
	else
		if(f == 0)	
			f = MAX-1;
		else
			--f;
	printf("\nEnter element to insert\n");
	scanf("%d",&q[f]);
	printf("\nSuccessfully inserted at Front\n");
}

void insert_r()
{
	if((f == 0 && r == MAX -1) || (f == r+1))
	{
		printf("\nDeque is Overflow");
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
	printf("\nEnter element to insert\n");
	scanf("%d",&q[r]);
	printf("\nSuccessfully inserted at Rear\n");
}

void delete_f()
{
	if(f==-1)
	{
		printf("\nDeque is Underflow");
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
	printf("\nSuccessful Deletion at Front\n");
}

void delete_r()
{
	if(f==-1)
	{
		printf("\nDeque is Underflow");
		return;
	}
	printf("Deleted element is : %d\n",q[r]);
	if(f==r)
	{
		q[r] = '\0';
		f = -1;
		r = -1;
	}
	else
		if(r == 0)
			r = MAX-1;
		else
			--r;
	printf("\nSuccessful Deletion at Rear\n");
}

void display()
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
}
