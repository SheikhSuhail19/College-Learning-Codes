#include<stdio.h>
#include<conio.h>
void main()
{
	int stack[100], top=-1, remainder, decimal;
	printf("Enter decimal number\n");
	scanf("%d",&decimal);
	while(decimal != 0)
	{
		remainder=decimal%2;
		decimal=decimal/2;
		stack[++top]=remainder;
	}
	printf("Binary equivalent is\n");
	for(;top>-1;top++)
		printf("%d",stack[top]);
	getch();
}