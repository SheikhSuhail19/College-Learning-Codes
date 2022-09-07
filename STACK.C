#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define max 30
int stack[max], top;
void push(), pop(), display(), peek();
void main()
{
    int ch = 1, top = -1;
    clrscr();
    while (ch)
    {
	printf("\n1 PUSH\n2 POP\n3 PEEK\n Enter your choice");
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:
	    push();
	    break;
	case 2:
	    pop();
	    break;
	case 3:
	    peek();
	    break;
	default:
	    exit(0);
	}
    }
    getch();
}

void push()
{
    int n;
    if(top == max - 1)
    {
	printf("\nSTACK OVERFLOW\n");
	return;
    }
    top++;
    printf("\nEnter number");
    scanf("%d", &n);
    stack[top] =n;
    display();
}
void pop()
{
    if (top == -1)
    {
	printf("\nSTACK UNDERFLOW\n");
	return;
    }
    else
    {
    top--;
    display();
    }
}
void peek()
{
    if (top == -1)
    {
        printf("\nSTACK UNDERFLOW\n");
        return;
    }
    printf("\n%d\t", stack[top]);
}
void display()
{
    int i;
    printf("Elements in Stack are : \n");
    for ( i = 0; i <= top; i++)
    {
	printf("\n%d\t",stack[i]);
    }

}