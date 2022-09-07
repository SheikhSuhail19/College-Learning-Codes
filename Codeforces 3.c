#include<stdio.h>
int main(){
  long int n;
  int k,i;
  scanf("%ld %d",&n,&k);
  for(i=0;i<k;i++)
    {
      if(n%10==0)
      n=n/10;
      else
      n--;
    }
    printf("%d",n);
}