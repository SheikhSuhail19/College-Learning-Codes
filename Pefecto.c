#include<stdio.h>
int main()
{
  long int a[100],s;
  int t,n,i;
  scanf("%d",&t);
  for(i=0;i<t;i++)
  {
    scanf("%ld",&a[i]);
  }
  for(i=0;i<t;i++)
  {s=0;
    for(n=1;n<a[i];n++)
    {
      if(a[i]%n==0)
      s=s+n;
    }
    if(s==a[i])
    printf("YES\n");
    else 
    printf("NO\n");
    }
 }
