#include<stdio.h>
int factors(long int x)
{
  int i,f=0,flag;
  for(i=1;i<x;i++)
  {
    if(x%i==0)
    {
      f=f+i;
    }
    else continue;
  }
  i=0;
  if(f==x)
  {
  flag=1;
  i++;
  }
  else
  {
  flag=-1;
  i++;
  }
  return flag;
}
int main()
{
  int t,i,a[100];
  long int n;
  scanf("%d",&t);
  for(i=0;i<t;i++)
  {
    scanf("%ld",&n);
    a[i]=factors(n);
  }
  for(i=0;i<t;i++)
  {
    if(a[i]==1)
    printf("YES\n");
    else printf("NO\n");
  }
}