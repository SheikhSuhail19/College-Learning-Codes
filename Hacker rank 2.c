#include<stdio.h>
void reverse(int x[],int s)
{
  int i,j,t;
  for(i=0;i<(s/2);i++)
  {
    for(j=s-i-1;;j--)
    {
      t=x[i];
      x[i]=x[j];
      x[j]=t;
      break;
    }
    if(i==j)
    break;
  }
  for(i=0;i<s;i++)
  {
  printf("%d ",x[i]);
  }
}
int main()
{
  int a[10000],n,i;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  reverse(a,n);
  return 0;
}