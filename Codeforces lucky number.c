#include<stdio.h>
int main()
{
  long long int n;
  int i,x,c=0;
  scanf("%lld",&n);
  do
  {
    x=n%10;
    if(x==4 || x==7)
     c++;
    n=n/10;
  }
  while(n!=0);
  if(c==4 || c==7)
   printf("YES");
  else
   printf("NO");
}