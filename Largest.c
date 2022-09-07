#include<stdio.h>
int main()
{
  int i,j,s,n;
  long int a[10][10],sl[10]={0},l[10]={0};
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    for(j=0;j<3;j++)
    {
      scanf("%ld",&a[i][j]);
      if(l[i]<a[i][j])
        l[i]=a[i][j];
    }
  }
  for(i=0;i<n;i++)
  {
    printf("%ld\n",l[i]);
  }
}