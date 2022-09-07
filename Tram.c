#include<stdio.h>
int main()
{
  int s=0,ex=0,en=0,i,sp=0,maxs=0;
  scanf("%d",&s);
  for(i=0;i<s;i++)
  {
    scanf("%d %d",&ex,&en);
      sp=sp+en-ex;
      if(sp>maxs)
      {
      maxs=sp;
      }
  }
  printf("%d",maxs);
}
 