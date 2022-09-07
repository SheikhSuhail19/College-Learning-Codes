#include<stdio.h>
#include<stdlib.h>
#define ll long long
int main()
{
  int i,n;
  ll int s=0,*a;
  scanf("%d",&n);
  a=(int*)malloc(sizeof(int)*n);
  for(i=0;i<n;i++)
  {
    scanf("%lld",a);
    s=s+(*a);
  }
  printf("%lld",s);
}