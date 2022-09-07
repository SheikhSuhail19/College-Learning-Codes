#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
	char S[50];
	int i, top = -1, n, x=0, y=0, stack[50];
	clrscr();
	printf("\nEnter postfix expression :");
	gets(S);
	n = strlen(S);
	printf("The value of postfix notation is :");
	for(i=0;i<n;i++)
	{
		switch(S[i])
		{
			case '+' :
			y=stack[top];
			x=stack[top-1];
			top--;
			x=x+y;
			stack[top]=x;
			break;
			
			case '-' :
			y=stack[top];
			x=stack[top-1];
			top--;
			x=x+y;
			stack[top]=x;
			break;
			
			case '*' :
			y=stack[top];
			x=stack[top-1];
			top--;
			x=x+y;
			stack[top]=x;
			break;
			
			case '/' :
			y=stack[top];
			x=stack[top-1];
			top--;
			x=x+y;
			stack[top]=x;
			break;
			
			case '^' :
			y=stack[top];
			x=stack[top-1];
			top--;
			x=pow(x,y);
			stack[top]=x;
			break;
			
			default:
			top++;
			if(S[i] >= 48 && S[i] <= 57)
			{
				x=S[i] - 48;
				stack[top] = x;
				x=0;
			}
		}
	}
	printf("%d", stack[top]);
	getch();
}