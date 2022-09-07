#include<stdio.h>
void reverseArray(int p[],int x)
{
  int i,j,t;
  for(i=0,j=x-1;i<x/2;i++,j--)
    {
      if(i==j)
      {break;}
     t=p[i];
     p[i]=p[j];
     p[j]=t;
    }
    for(i=0;i<x;i++)
    printf("%d ",p[i]);
}
int main()
{ int a[10],i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  reverseArray(a,n);
 return 0;
}
