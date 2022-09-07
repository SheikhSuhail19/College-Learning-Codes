#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
int stack[SIZE], top=-1;
void push(char item)
{
  if(top >= SIZE-1)
    printf("Stack Overflow");
  else
    {
      ++top;
      stack[top] = item;
    }
}

char pop()
{
  char item;
  if(top < 0)
    printf("Stack Underflow");
  else
    {
      item = stack[top];
      --top;
    }
  return item;
}
  
int is_operator(char symbol)
{
  switch(symbol)
  {
    case '+' :
    case '-' :
    case '*' :
    case '/' :
    case '^' :
    case ')' :
    case '(' :
      return 1;
  }
  return 0;
}

void InfixToPrefix(char infix[], char prefix[])
{
  int i=0,j=0;
  char symbol;
  reverse(infix);
  stack[++top]='#';
  for (i=0;i<strlen(infix);i++) 
  {
    symbol=infix[i];
    if (is_operator(symbol)==0) 
    {
      prefix[j]=symbol;
      j++;
    } 
    else 
    {
      if (symbol==')') 
      {
        push(symbol);
      } 
      else if(symbol == '(') 
      {
        while (stack[top]!=')') 
        {
          prefix[j]=pop();
          j++;
        }
        pop();
      } 
      else 
      {
        if (prcd(stack[top])<prcd(symbol)) 
        {
          push(symbol);
        } 
        else 
        {
          while(prcd(stack[top])>=prcd(symbol)) 
          {
            prefix[j]=pop();
            j++;
          }
          push(symbol);
        }
        //end for else
      }
    }
    //end for else
  }
  //end for for
  while (stack[top]!='#') 
  {
    prefix[j]=pop();
    j++;
  }
  prefix[j]='\0';
  printf("\nPrefix Expression is:\n");
  reverse(prefix);
  puts(prefix);
}

int prcd (char symbol)
{
  switch(symbol)
  {
    case '+': 
    case '-':
      return 2;
    case '*' :
    case '/':
      return 3;
    case '^':
      return 4;
    case '(':
    case ')':
      return 1;
  }
  return 0;
}

reverse(char *exp)
{
    int size = strlen(exp);
    int j = size, i=0;
    char temp[100];

    temp[j--]='\0';
    while(exp[i] != '\0')
    {
	temp[j] = exp[i];
	j--;
	i++;
    }
    strcpy(exp,temp);
}

int main()
{
  char prefix[SIZE],infix[SIZE];
  clrscr();
  printf("\nEnter Infix expression :");
  gets(infix);
  InfixToPrefix(infix,prefix);
  getch();
  return 0;
}