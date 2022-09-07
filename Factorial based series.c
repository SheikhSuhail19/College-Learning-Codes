#include<stdio.h>
#include<conio.h>
int fact(int);
void main()
{
  int i,n;
  float s=0.0;
  printf("Enter limit");
  scanf("%d",&n);
  for(i=0;i<=n;i++)
  {
    s=s+((i+1)/(float)(fact(2*i+3)));
  }
  printf("Sum of the series : ");
  for(i=0;i<n;i++)
  {
  	printf("%d/%d! + ",i+1,2*i+3);
  }
  printf("\b\b= %f",s);
  getch();
}
int fact(int x)
{
  int fa=1,i;
  for(i=1;i<=x;i++)
  {
    fa=fa*i;
  }
  return fa;
}