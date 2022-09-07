#include<stdio.h>
int main()
{
  int n,i;
  long int a[21];
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%ld",&a[i]);
  }
  for(i=0;i<n;i++)
  {
  printf("%ld\n",a[i]);
  }
  return 0;
}