#include<stdio.h>
#define SQ(x) (x)*(x)
int main()
{
  int n,i,a[1000];
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++)
  {
    printf("%d\n",SQ(a[i]));
  }
  return 0;
}