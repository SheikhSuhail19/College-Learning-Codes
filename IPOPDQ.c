/*Implementation of IP/OP Restricted Dequeue using Array*/

#include<stdio.h>
#include<conio.h>
#define MAX 100

int q[MAX], f=-1,r=-1;

void main()
{
	int ch;
	void ip_q(),op_q(),insert_f(),insert_r(),delete_f(),delete_r(),display();
	clrscr();
	while(1)
	{
		printf("\n1. Input Restricted Queue\n2. Output Restricted Queue\n3. Exit");
		printf("\nEnter Your Choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				ip_q();
				break;
			case 2:
				op_q();
				break;
			case 3:
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
		printf("\nDeque Overflow");
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
	printf("\nEnter element\n");
	scanf("%d",&q[f]);
	printf("\nSuccessfully inserted at Front\n");
}

void insert_r()
{
	if((f == 0 && r == MAX -1) || (f == r+1))
	{
		printf("\nDeque Overflow");
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
	printf("\nSuccessfully inserted at Rear\n");
}

void delete_f()
{
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
	printf("\nDeleted successfully at Front\n");
}

void delete_r()
{
	if(f==-1)
	{
		printf("\nUnderflow");
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
	printf("\nDeleted successfully at Rear\n");
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

void ip_q()
{
	int ch;
	while(1)
	{
		printf("\n1. Insert at Rear\n2. Delete at Front\n3. Delete at Rear");
		printf("\n4. Display\n5. Exit\nEnter Your Choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert_r();
				break;
			case 2:
				delete_f();
				break;
			case 3:
				delete_r();
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
			default:
				printf("Invalid Choice\n");
		}
	}
}
	
void op_q()
{
	int ch;
	while(1)
	{
		printf("\n1. Insert at Front\n2. Insert at Rear\n3. Delete at Front");
		printf("\n4. Display\n5. Exit\nEnter Your Choice\n");
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
				display();
				break;
			case 5:
				exit(0);
			default:
				printf("Invalid Choice\n");
		}
	}
}
